cmake_minimum_required(VERSION 3.25)
project(class_sample C)

set(CMAKE_C_STANDARD 11)

add_executable(class_sample main.c animal.h cat.h cat.c)
