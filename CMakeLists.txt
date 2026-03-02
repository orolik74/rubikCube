cmake_minimum_required(VERSION 4.0)
project(untitled7)

set(CMAKE_CXX_STANDARD 20)

add_executable(main src/main.cpp)
add_executable(gen src/gen_cubes.cpp)
add_definitions("-DLOCAL")

target_link_libraries(main PRIVATE z3)
