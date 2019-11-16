cmake_minimum_required(VERSION 2.6)

set(This Snaze)

project(${This} CXX)
set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(src)

set(Headers
    Snaze.h
)
set(Sources
    Snaze.cpp
)