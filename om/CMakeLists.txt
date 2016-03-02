cmake_minimum_required(VERSION 3.4)
project(OM)

MESSAGE(STATUS ${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(OM om.h om.cpp)
add_library(${PROJECT_NAME} SHARED
        ${OM})

set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
        CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)