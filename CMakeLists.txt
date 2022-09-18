cmake_minimum_required(VERSION 3.22)
project(puubie C)

set(CMAKE_C_STANDARD 99)

add_executable(puubie src/main.c src/net/socket.c src/log/syslog.c)
