#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define JSTP_SERVER_EXPORT __declspec(dllexport)
#else
  #define JSTP_SERVER_EXPORT
#endif

JSTP_SERVER_EXPORT void jstp_server();
JSTP_SERVER_EXPORT void jstp_server_print_vector(const std::vector<std::string> &strings);
