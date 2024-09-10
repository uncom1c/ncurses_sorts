cmake_minimum_required( VERSION 3.10 )

add_library(sorts STATIC sorts.cpp)

target_include_directories(sorts PUBLIC include)
