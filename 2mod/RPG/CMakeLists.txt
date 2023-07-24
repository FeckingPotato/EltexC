cmake_minimum_required(VERSION 3.24)
project(RPG C)

set(CMAKE_C_STANDARD 23)

add_executable(RPG main.c base/character.c base/character.h system/utils.c system/utils.h items/equipment.c items/equipment.h base/world.c base/world.h system/ui.c system/ui.h items/healing.c items/healing.h system/save.c system/save.h adventures/enemy.h)
