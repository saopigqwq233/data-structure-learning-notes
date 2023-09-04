cmake_minimum_required(VERSION 3.26)
project(Sort C)

set(CMAKE_C_STANDARD 11)

add_executable(Sort main.c
        插入排序.c
        pre.h
        希尔排序.c
        选择排序.c
        堆排序.c)
