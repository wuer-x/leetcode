cmake_minimum_required(VERSION 3.3)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES ./single_number/single_number.cpp)
#set(SOURCE_FILES ./stl_test/test_vector.cpp)
add_executable(leetcode ${SOURCE_FILES})