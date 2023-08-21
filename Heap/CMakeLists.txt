cmake_minimum_required(VERSION 3.26)
project(Heap C)

set(CMAKE_C_STANDARD 11)


add_executable(Heap main.c
        Heap.c
        Heap.h
        TopKtest.c)
