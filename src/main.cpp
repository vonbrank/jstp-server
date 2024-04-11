#include "jstp-server.h"
#include <vector>
#include <string>

int main() {
    jstp_server();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    jstp_server_print_vector(vec);
}
