cmake_minimum_required(VERSION 3.26)
project(Stack C)

set(CMAKE_C_STANDARD 11)

add_executable(Stack main.c
        Stack.h
        stack.c)
