cmake_minimum_required( VERSION 3.10 )

add_library(picturing STATIC picturing.cpp)

target_include_directories(picturing PUBLIC include)
