cmake_minimum_required(VERSION 3.22)
project(pupkin C)

set(CMAKE_C_STANDARD 99)

add_executable(pupkin src/main.c src/queue/queue.c )
