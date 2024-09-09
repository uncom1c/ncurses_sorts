cmake_minimum_required( VERSION 3.10 )

add_library(random STATIC random.cpp)

target_include_directories(random PUBLIC include)
