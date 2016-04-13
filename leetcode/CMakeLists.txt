cmake_minimum_required(VERSION 3.3)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES 213_house_robber_2/main.cpp)
add_executable(leetcode ${SOURCE_FILES})
