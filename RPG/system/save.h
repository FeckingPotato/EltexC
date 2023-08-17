#pragma once
#include "../base/character.h"
#include "../base/world.h"

int save(char* path, character_t* character, world_t* world);

int load(char* path, character_t* character, world_t* world);