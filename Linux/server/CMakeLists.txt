project(server)

include_directories(.)

cmake_minimum_required(VERSION 2.6)
aux_source_directory(./src dir_srcs)

# serverLib
add_subdirectory(./lib)

# hserver
link_libraries(bin/hserver serverLib)
add_executable(bin/hserver src/hello_server.c)
