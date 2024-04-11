#include "jstp-server.h"
#include "jstp_server.h"
#include <vector>
#include <string>

int main()
{
    using namespace network;
    JstpServer server = JstpServer("127.0.0.1", 5001);
    server.run();
}
