cmake_minimum_required(VERSION 3.15)
project(jstp-server CXX)

aux_source_directory(src DIR_SRC)

add_executable(jstp-server ${DIR_SRC})
# target_include_directories(jstp-server PUBLIC "include/")

TARGET_LINK_LIBRARIES( jstp-server
        pthread
)


install(TARGETS jstp-server DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )

find_package(nlohmann_json REQUIRED)
target_link_libraries(jstp-server nlohmann_json::nlohmann_json)