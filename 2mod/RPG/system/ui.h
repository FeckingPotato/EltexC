#pragma once
#include "../base/character.h"
#include "../base/world.h"

void init(character_t* character, world_t* world);

void printSkills(character_t* character);

int levelUp(unsigned int points, character_t* character);

int mainMenu(character_t* character, world_t* world);

void adventure(character_t* character, world_t* world);

void shop(character_t* character, world_t* world);

void boss(character_t* character, world_t* world);

void sleep(character_t* character, world_t* world);

void stats(character_t* character, world_t* world);
