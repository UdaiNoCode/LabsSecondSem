cmake_minimum_required(VERSION 3.28)
project(LAB4)

set(CMAKE_CXX_STANDARD 26)

add_executable(LAB4 main.cpp
        simpleAllocator.h
        vector.cpp
        vector.h
)
