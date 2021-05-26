cmake_minimum_required(VERSION 3.17)
project(grep-with-marketing)

set(CMAKE_C_STANDARD 99)

enable_testing()
add_subdirectory(src)
add_subdirectory(test)

add_executable(basicgrep main.c)
target_link_libraries(basicgrep src)

