cmake_minimum_required(VERSION 3.3)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES 100_same_tree/100_same_tree.cpp)
add_executable(leetcode ${SOURCE_FILES})