cmake_minimum_required(VERSION 3.27)
project(designated_initializer_struct C)

set(CMAKE_C_STANDARD 11)

add_executable(designated_initializer_struct main.c
        student.h)
