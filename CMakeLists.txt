cmake_minimum_required(VERSION 3.15)
project(Othello C)

set(CMAKE_C_STANDARD 99)

add_executable(Othello main.c damier.c header.h deplacement.c)