cmake_minimum_required(VERSION 3.24)
project(Galileo)

set(CMAKE_CXX_STANDARD 20)

set(sources ${sources} src/main.cpp)

add_executable(Galileo ${sources})
