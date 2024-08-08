cmake_minimum_required(VERSION 3.20)

enable_language(C)

project(program)


set(CMAKE_C_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_SOURCE_DIR}>)

add_executable(program btree.c main.c btree.h)