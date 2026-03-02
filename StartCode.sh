#!/bin/bash

g++ -std=c++20 src/gen_cubes.cpp  -O3 -o gen
g++ -std=c++20 src/main.cpp -O3 -o main -lz3
echo "compile done"

./gen
echo "Начало работы main"
./main
echo "Done"
rm -f gen main allCubes.txt