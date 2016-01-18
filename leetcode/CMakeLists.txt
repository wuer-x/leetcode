cmake_minimum_required(VERSION 3.3)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES max_depth_of_binary_tree/max_depth_of_binary_tree.cpp)
add_executable(leetcode ${SOURCE_FILES})