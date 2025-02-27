#pragma once

#ifdef FZ_PLATFORM_WINDOWS
    #define _WIN32_WINNT 0x0A00
#endif

#define ASIO_STANDALONE
#include <asio.hpp>

#include <memory>
#include <string>

namespace Fazon {

    class Server {

    public:
        Server(asio::io_context& ioContext, uint32_t port);
        ~Server() {
            if (m_acceptor.is_open()) {
                m_acceptor.close();
            }
        }

    private:
        void startAccept();
        void handleWrite(std::shared_ptr<asio::ip::tcp::socket> socket,
            std::shared_ptr<std::string> message,
            const asio::error_code& error);

    private:

        asio::ip::tcp::acceptor m_acceptor;
        bool m_running{ true };

    };
}
