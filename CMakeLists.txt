cmake_minimum_required(VERSION 3.16)
project(habit CXX)

set(CMAKE_CXX_STANDARD 20)

add_library (libhabit INTERFACE)
target_include_directories(libhabit INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(tests)