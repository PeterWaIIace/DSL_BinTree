cmake_minimum_required(VERSION 3.20)

enable_language(CXX)

project(program)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_SOURCE_DIR}>)

add_executable(bt_compiler dsl_compiler.cpp dsl_tokenizer.cpp dsl_tokenizer.hpp dsl_tree.cpp dsl_tree.hpp)