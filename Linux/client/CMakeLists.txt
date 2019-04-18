project(client)

include_directories(.)

cmake_minimum_required(VERSION 2.6)
aux_source_directory(./src dir_srcs)

# clientLib
add_subdirectory(./lib)

# hclient
link_libraries(bin/hclient clientLib)
add_executable(bin/hclient src/hello_client.c)
