include_directories(.)
cmake_minimum_required(VERSION 2.6)
aux_source_directory(. libPath)
add_library(serverLib ${libPath})
