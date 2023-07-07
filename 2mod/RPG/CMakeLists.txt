cmake_minimum_required(VERSION 3.25)
project(RPG C)

set(CMAKE_C_STANDARD 23)

add_executable(RPG main.c character.c character.h utils.c utils.h items.c items.h world.c world.h ui.c ui.h)
