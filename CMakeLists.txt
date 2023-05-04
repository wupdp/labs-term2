cmake_minimum_required(VERSION 3.24)
project (lab1_1 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab1 Term_2/src/lab1/main.c Term_2/src/lab1/functions.c Term_2/src/lab1/header.h)
add_executable(lab2_compression Term_2/src/lab2/compression/main.c Term_2/src/lab2/compression/functions.c Term_2/src/lab2/compression/header.h)
add_executable(lab2_decompression Term_2/src/lab2/decompression/main.c Term_2/src/lab2/decompression/functions.c Term_2/src/lab2/decompression/header.h)
add_executable(lab3 Term_2/src/lab3/main.c Term_2/src/lab3/functions.c Term_2/src/lab3/header.h)