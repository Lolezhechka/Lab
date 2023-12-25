cmake_minimum_required(VERSION 3.26)
project(UltKR)

set(CMAKE_CXX_STANDARD 17)

add_executable(UltKR main.cpp
        Animal.h
        Animal.cpp
        AppZoo.cpp
        Date.cpp
        testAnimal.cpp
        testDate.cpp)
