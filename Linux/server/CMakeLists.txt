project(server)

include_directories(.)

cmake_minimum_required(VERSION 2.6)
aux_source_directory(./src dir_srcs)

# serverLib
add_subdirectory(./lib)

# hserver
add_executable(bin/hserver src/hello_server.c)
target_link_libraries(bin/hserver serverLib)

# lopen
add_executable(bin/lopen src/low_open.c)
target_link_libraries(bin/lopen serverLib)

# lread
add_executable(bin/lread src/low_read.c)
target_link_libraries(bin/lread serverLib)

# fds
add_executable(bin/fds src/fd_seri.c)
target_link_libraries(bin/fds serverLib)
