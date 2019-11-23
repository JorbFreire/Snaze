cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests ${CMAKE_SOURCE_DIR}/../../src/tests/maze_tests.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)