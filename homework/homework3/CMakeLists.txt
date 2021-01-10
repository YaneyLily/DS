cmake_minimum_required(VERSION 3.17)
project(homework3)

set(CMAKE_CXX_STANDARD 14)
aux_source_directory(. DIR_SRCS)
add_executable(out ${DIR_SRCS})
#add_executable(homework3 main.cpp)