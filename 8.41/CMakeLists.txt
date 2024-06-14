cmake_minimum_required(VERSION 3.27)
project(8_41 C)

set(CMAKE_C_STANDARD 11)

add_executable(8_41 cipher.c
        cmake-build-debug/cipher.h
        cipher.h)
