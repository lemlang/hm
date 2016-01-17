cmake_minimum_required(VERSION 3.4)
project(cpp_hm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp hm.h hm.cpp Example.h Example.cpp)
add_executable(cpp_hm ${SOURCE_FILES})