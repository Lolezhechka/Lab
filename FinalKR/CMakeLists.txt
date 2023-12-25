cmake_minimum_required(VERSION 3.26)
project(Zoo_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Zoo_Project
        Animal.cpp
        Animal.h
        AppZoo.cpp
        AppZoo.h
        Date.cpp
        Date.h
        main.cpp
        testAnimal.cpp
        testDate.cpp)
