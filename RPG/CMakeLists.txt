cmake_minimum_required(VERSION 3.16)
project(RPG)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(RPG
        src/hero.cpp
        src/monster.cpp
        src/profession.cpp
        src/RPG.cpp)
