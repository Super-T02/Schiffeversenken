cmake_minimum_required(VERSION 3.17)
project(Schiffeversenken C)

set(CMAKE_C_STANDARD 11)

include_directories(Files)

add_executable(Schiffeversenken
        Files/End.c
        Files/End.h
        Files/Global.h
        Files/Main.c
        Files/Play.c
        Files/Play.h
        Files/Start.c
        Files/Start.h)
