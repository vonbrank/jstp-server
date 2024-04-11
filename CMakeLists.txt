cmake_minimum_required(VERSION 3.15)
project(jstp-server CXX)

aux_source_directory(src DIR_SRC)

add_executable(jstp-server ${DIR_SRC})

TARGET_LINK_LIBRARIES( jstp-server
        pthread
)


install(TARGETS jstp-server DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
