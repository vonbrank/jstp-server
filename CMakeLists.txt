cmake_minimum_required(VERSION 3.15)
project(jstp-server CXX)



add_executable(jstp-server src/jstp-server.cpp src/main.cpp)



install(TARGETS jstp-server DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
