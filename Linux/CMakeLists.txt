project(tcp_ip)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

execute_process(
    COMMAND cmake ./server
    COMMAND cmake ./client
)
