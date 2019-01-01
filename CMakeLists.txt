cmake_minimum_required(VERSION 3.13)
project(RAS111)

set(CMAKE_CXX_STANDARD 14)

add_executable(RAS111 src/main.cpp include/DataStructures/Graph/Graph.h)

add_executable(RAS111Tester tests/tester.cpp)
target_include_directories(RAS111Tester PRIVATE include)