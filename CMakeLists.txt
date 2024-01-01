cmake_minimum_required(VERSION 3.27)
project(GUI_Playground)

set(CMAKE_CXX_STANDARD 23)

add_executable(GUI_Playground main.cpp
        ConsoleMenu.cpp
        ConsoleMenu.hpp)
