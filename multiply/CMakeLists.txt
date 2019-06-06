cmake_minimum_required(VERSION 3.14)
project(multiply C)

set(CMAKE_C_STANDARD 11)

add_executable(multiply main.c multiply.c multiply.h)