#include "jstp_server.h"
#include "utils.h"
#include <algorithm>
#include <cstddef>
#include <sstream>
#include <stdio.h>
#include <unistd.h>

namespace network
{
    JstpServer::JstpServer(std::string ip_address, int port) :
        tcpServer(TcpServer(ip_address, port))
    {
        tcpServer.AddConnectionHandler(this);
    }

    JstpServer::~JstpServer()
    {
        tcpServer.RemoveConnectionHandler(this);
    }

    void JstpServer::run()
    {
        tcpServer.run();
    }
    void JstpServer::handleConnection(int handling_socket)
    {
        utils::log("[jstp-server] Handling connection...");

        size_t BUFFER_SIZE = 1024;
        char buffer[BUFFER_SIZE];
        size_t totalBytesRead = 0;
        std::ostringstream ss_data;

        while (true)
        {
            int bytesRead = read(handling_socket, buffer, BUFFER_SIZE);

            if (bytesRead == 0)
            {
                break;
            }

            totalBytesRead += bytesRead;
            buffer[bytesRead] = '\0';
            ss_data << buffer;

            auto data_str = ss_data.str();
            int bytesWritten = write(handling_socket, buffer, bytesRead);

            if (bytesWritten != bytesRead)
            {
                utils::log("[jstp-server] Failed to sending response to client.");
            }
        }

        utils::log(ss_data.str());

        utils::log("[jstp-server] Connection closed...");
    }

} // namespace network