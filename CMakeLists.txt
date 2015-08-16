cmake_minimum_required(VERSION 2.8)
project(sprout)
set(CMAKE_CXX_FLAGS "-O0 -Wall -pedantic -std=c++11")
add_executable(sprout main.cpp)
install(TARGETS sprout DESTINATION bin)

