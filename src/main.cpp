#include "jstp-server.h"
#include "jstp_router.h"
#include "jstp_server.h"
#include "utils.h"
#include <cstdlib>
#include <memory>
#include <vector>
#include <string>
#include <csignal>

std::shared_ptr<network::JstpServer> jstp_server_instance;

void signalHandler(int signal)
{
    utils::log("\n");

    if (jstp_server_instance.get())
    {
        utils::log("Closing running JSTP server...");
        jstp_server_instance->~JstpServer();
    }

    exit(0);
}

int main()
{
    signal(SIGINT, signalHandler);

    using namespace network;

    std::shared_ptr<JstpServer> server(new JstpServer("127.0.0.1", 5101));
    jstp_server_instance = server;

    std::unique_ptr<AppRouter> app_router(new AppRouter());
    server->add_router(std::move(app_router));

    server->run();

    return 0;
}
