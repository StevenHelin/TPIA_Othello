cmake_minimum_required(VERSION 3.15)
project(Othello C)

set(CMAKE_C_STANDARD 99)

add_executable(Othello sources/main.c sources/damier.c header.h sources/deplacement.c sources/detection.c sources/prise.c)