#ifndef HTTP_ROUTER_H
#define HTTP_ROUTER_H
#include "nlohmann/json.hpp"

namespace network
{
    class JstpRouter
    {
        using json = nlohmann::json;

    public:
        virtual void handleRequest(json &request, json &response){};
    };
} // namespace network

#endif