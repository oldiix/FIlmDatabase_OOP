cmake_minimum_required(VERSION 3.29)
project(lab_1_oop)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_1_oop main.cpp
        Film.cpp
        Film.h
        Actor.cpp
        Actor.h
        Director.cpp
        Director.h
)
