cmake_minimum_required(VERSION 3.28)
project(Task4)

set(CMAKE_CXX_STANDARD 26)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_executable(Task4 main.cpp
        simpleAllocator.h
        vector.cpp
        vector.h
)
