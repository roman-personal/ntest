cmake_minimum_required(VERSION 3.0.0)
project(ntest VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(/usr/src/googletest gtest)