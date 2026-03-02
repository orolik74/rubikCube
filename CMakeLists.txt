cmake_minimum_required(VERSION 4.0)
project(untitled7)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled7 main.cpp)
add_executable(gen gen_cubes.cpp)
add_definitions("-DLOCAL")

target_link_libraries(untitled7 PRIVATE z3)
