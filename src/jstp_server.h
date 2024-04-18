#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include "server.h"
#include <cstddef>
#include <string>
#include "tcp_server.h"
#include "nlohmann/json.hpp"

namespace network
{
    class JstpServer : public IServer, public IConnectionHandler
    {
        using json = nlohmann::json;

    public:
        JstpServer(std::string ip_address, int port);
        ~JstpServer();
        void run() override;

    private:
        TcpServer tcpServer;

    private:
        void handleConnection(int handling_socket) override;
        std::string readBytesFromSocket(int handling_socket, size_t numBytes);
        static json defaultResponse();
    };
} // namespace network

#endif