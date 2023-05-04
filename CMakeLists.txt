cmake_minimum_required(VERSION 3.24)
project (lab1_1 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab1 src/lab1/main.c src/lab1/functions.c src/lab1/header.h)
add_executable(lab2_compression src/lab2/compression/main.c src/lab2/compression/functions.c src/lab2/compression/header.h)
add_executable(lab2_decompression src/lab2/decompression/main.c src/lab2/decompression/functions.c src/lab2/decompression/header.h)
add_executable(lab3 src/lab3/main.c src/lab3/functions.c src/lab3/header.h)