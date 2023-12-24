cmake_minimum_required(VERSION 3.25)
project(file_sample C)

set(CMAKE_C_STANDARD 11)

add_executable(file_sample main.c fgets.c fgets.h)

file(GLOB CONFIG_FILES "conf/*.conf")
file(COPY ${CONFIG_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})