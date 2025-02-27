#pragma once

#ifdef FZ_PLATFORM_WINDOWS
    #define _WIN32_WINNT 0x0A00
#endif

#define ASIO_STANDALONE
#include <asio.hpp>

#include <memory>

namespace Fazon {

    class Client {

    public:
        Client(asio::io_context& ioContext, const std::string& serverIP, uint32_t port);
        ~Client() {
            if (m_socket.is_open()) {
                m_socket.close();
            }
        }

        bool isConnected() const { return m_socket.is_open(); }

    private:

        void readMessage();
        void handleRead(const asio::error_code& error, std::size_t bytesTransferred);
        void handleConnect(const asio::error_code& error, const asio::ip::tcp::endpoint& endpoint);

    private:

        asio::ip::tcp::socket m_socket;
        asio::streambuf m_streambuf;
        bool m_isReading{ false };

    };
}