cmake_minimum_required(VERSION 2.6)

set(This Snaze)

project(${This} CXX)
set(CMAKE_CXX_STANDARD 11)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests sqrt_test.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)

add_subdirectory(src)

set(Headers
    Snaze.h
)
set(Sources
    Snaze.cpp
)