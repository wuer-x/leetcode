cmake_minimum_required(VERSION 3.3)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES 7_reverse_int/7_reverse_int.cpp 66_plus_one/66_plus_one.cpp)
#set(SOURCE_FILES delete_node_in_a_linked_list.cpp)
add_executable(leetcode ${SOURCE_FILES})