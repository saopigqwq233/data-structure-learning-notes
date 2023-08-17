cmake_minimum_required(VERSION 3.24)
project(LinkQueue C)

set(CMAKE_C_STANDARD 11)

add_executable(LinkQueue main.c LinkQueue.h RealizeQueuefunc.c)
