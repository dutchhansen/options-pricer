cmake_minimum_required(VERSION 3.24)
project(options_pricer)

set(CMAKE_CXX_STANDARD 17)

add_executable(options_pricer main.cpp blackscholes.cpp)
