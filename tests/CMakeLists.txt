enable_testing()

include_directories(${OM_INCLUDE_DIRS})
set(TESTS test_hanging_reference.cpp Example.h Example.cpp)
add_executable(test_hanging_reference ${TESTS} )
target_link_libraries(test_hanging_reference OM)
add_test(test_hanging_reference ${CMAKE_CURRENT_BINARY_DIR}/test_hanging_reference )