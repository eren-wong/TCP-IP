project(client)

include_directories(.)

cmake_minimum_required(VERSION 2.6)
aux_source_directory(./src dir_srcs)

# clientLib
add_subdirectory(./lib)

# hclient
add_executable(bin/hclient src/hello_client.c)
target_link_libraries(bin/hclient clientLib)
