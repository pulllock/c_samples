cmake_minimum_required(VERSION 3.25)
project(struct_sample C)

set(CMAKE_C_STANDARD 11)

add_executable(struct_sample main.c user.c user.h book.c book.h friend.c friend.h)
