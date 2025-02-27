#include "Server.h"
#include "Fazon/fzpch.h"

namespace Fazon {

    Server::Server(asio::io_context& ioContext, uint32_t port)
        : m_acceptor{ ioContext, asio::ip::tcp::endpoint{ asio::ip::tcp::v4(), static_cast<asio::ip::port_type>(port) } }
    {
        startAccept();
    }

    void Server::handleWrite(std::shared_ptr<asio::ip::tcp::socket> socket,
        std::shared_ptr<std::string> message,
        const asio::error_code& error) {

        if (error) {
            if (error != asio::error::operation_aborted) {
                FZ_CORE_CRITICAL("Write error: {0}", error.message());
            }
            if (socket->is_open()) {
                socket->close();
            }
        }

    }

    void Server::startAccept() {

        if (!m_running) return;

        auto socket{ std::make_shared<asio::ip::tcp::socket>(m_acceptor.get_executor()) };

        m_acceptor.async_accept(*socket,
            [this, socket](const asio::error_code& error) {
                if (error) {
                    if (error != asio::error::operation_aborted) {
                        FZ_CORE_CRITICAL("Accept error: {0}", error.message());
                    }
                }
                else {
                    FZ_CORE_TRACE("New client connected!");
                    std::string htmlMessage = "HTTP/1.1 200 OK\r\n"
                        "Content-Type: text/html\r\n"
                        "Content-Length: 46\r\n"
                        "Connection: close\r\n"
                        "\r\n"
                        "<html><body><h1>Hello, Client!</h1></body></html>";
                    auto message{ std::make_shared<std::string>(htmlMessage) };
                    asio::async_write(*socket, asio::buffer(*message),
                        [this, socket, message](const asio::error_code& error, std::size_t /*bytesTransferred*/) {
                            handleWrite(socket, message, error);
                        });
                }

                if (m_running) {
                    startAccept();
                }
            });

    }
}