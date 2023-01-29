cmake_minimum_required(VERSION 3.24)
project(Seq C)

set(CMAKE_C_STANDARD 11)

add_executable(Seq main.c SeqQueue.h RealizeQueueFunc.c)
