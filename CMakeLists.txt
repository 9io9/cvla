cmake_minimum_required(VERSION 3.28)
project(cvla C)

set(CMAKE_C_STANDARD 17)

set(BUILD_SHARED_LIBS off)

add_library(cvla cvla.c cvla.h
        cvla.def.h
        cvla.err.h)

add_executable(cvlatest test.c)

target_link_libraries(cvlatest cvla)