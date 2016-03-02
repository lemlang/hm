cmake_minimum_required(VERSION 3.4)
project(example)

include_directories(${OM_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES main.cpp Example.h Example.cpp ExampleB.h ExampleB.cpp)
add_executable(example ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} OM)

add_library(${PROJECT_NAME}_LIB STATIC ${SOURCE_FILES})

set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
        CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
