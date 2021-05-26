cmake_minimum_required(VERSION 3.17)
project(grep-with-marketing)

set(CMAKE_C_STANDARD 99)

add_executable(basicgrep main.c cloudservice.c)
