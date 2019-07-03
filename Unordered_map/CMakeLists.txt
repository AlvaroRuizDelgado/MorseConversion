cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(morse LANGUAGES CXX)

add_executable(
    morse
    main.cpp
    morse.cpp
    timer.hpp
)