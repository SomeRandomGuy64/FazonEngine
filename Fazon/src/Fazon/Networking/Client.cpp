#include "Client.h"
#include "Fazon/fzpch.h"

namespace Fazon {

    Client::Client(asio::io_context& ioContext, const std::string& serverIP, uint32_t port)
        : m_socket{ ioContext }
    {
        try {
            asio::ip::tcp::resolver resolver{ ioContext };
            asio::ip::tcp::resolver::results_type endpoints{
                resolver.resolve(serverIP, std::to_string(port))
            };

            asio::async_connect(m_socket, endpoints,
                [this](const asio::error_code& error, const asio::ip::tcp::endpoint& endpoint) {
                    handleConnect(error, endpoint);
                });
        }
        catch ([[maybe_unused]]const std::exception& e) {
            FZ_CORE_ASSERT(false, "Connection setup error: {0}", e.what());
        }
    }

    void Client::handleConnect(const asio::error_code& error, [[maybe_unused]]const asio::ip::tcp::endpoint& endpoint) {

        if (!error) {
            FZ_CORE_TRACE("Connected to server at {0}:{1}",
                endpoint.address().to_string(),
                endpoint.port());
            readMessage();
        }
        else {
            if (error != asio::error::operation_aborted) {
                FZ_CORE_ERROR("Connect error: {0}", error.message());
            }
            if (m_socket.is_open()) {
                m_socket.close();
            }
        }

    }

    void Client::handleRead(const asio::error_code& error, std::size_t /*bytesTransferred*/) {

        if (!error) {
            std::string message;
            std::istream is{ &m_streambuf };
            std::getline(is, message);

            FZ_CORE_TRACE("Server says: {0}", message);

            // Continue reading only if still connected
            if (m_socket.is_open()) {
                readMessage();
            }
        }
        else {
            if (error == asio::error::eof) {
                FZ_CORE_TRACE("Server closed connection");
            }
            else if (error != asio::error::operation_aborted) {
                FZ_CORE_ERROR("Read error: {0}", error.message());
            }

            if (m_socket.is_open()) {
                m_socket.close();
            }
        }
        m_isReading = false;

    }

    void Client::readMessage() {

        if (!m_socket.is_open() || m_isReading) return;

        m_isReading = true;
        asio::async_read_until(m_socket, m_streambuf, '\n',
            [this](const asio::error_code& error, std::size_t bytesTransferred) {
                handleRead(error, bytesTransferred);
            });

    }
}