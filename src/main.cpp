#include "jstp-server.h"
#include "jstp_server.h"
#include "utils.h"
#include <cstdlib>
#include <vector>
#include <string>
#include <csignal>

network::JstpServer *jstpServerInstance = nullptr;

void signalHandler(int signal)
{
    utils::log("\n");

    if (jstpServerInstance)
    {
        utils::log("Closing running JSTP server...");
        jstpServerInstance->~JstpServer();
    }

    exit(0);
}

int main()
{
    signal(SIGINT, signalHandler);

    using namespace network;
    JstpServer server = JstpServer("127.0.0.1", 5101);
    jstpServerInstance = &server;
    server.run();

    return 0;
}
