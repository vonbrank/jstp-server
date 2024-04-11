#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include "server.h"
#include <cstddef>
#include <string>
#include "tcp_server.h"

namespace network
{
    class JstpServer : public IServer, public IConnectionHandler
    {
    public:
        JstpServer(std::string ip_address, int port);
        ~JstpServer();
        void run() override;

    private:
        TcpServer tcpServer;

    private:
        void handleConnection(int handling_socket) override;
    };
} // namespace network

#endif