project(server)

include_directories(.)

cmake_minimum_required(VERSION 2.6)
aux_source_directory(./src dir_srcs)
add_subdirectory(./lib)

# hserver
add_executable(bin/hserver src/hello_server.c)
target_link_libraries(bin/hserver serverLib)
