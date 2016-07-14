cmake_minimum_required(VERSION 3.3)
project(cpp_om)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

enable_testing()
add_subdirectory(om)
add_subdirectory(tests)
add_subdirectory(example)

