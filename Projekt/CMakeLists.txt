cmake_minimum_required(VERSION 4.0)
project(Projekt)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projekt main.cpp
        car.cpp
        car.h
        utils.cpp
        utils.h)
