#pragma once

#include "../base/character.h"
#include "../base/world.h"

void init(character_t* character, world_t* world);

void printSkills(character_t* character);

int levelUp(unsigned int points, character_t* character);

int mainMenu(world_t *world);

void shop(character_t *character);

bool fight(character_t *character);

bool boss(character_t* character, world_t* world);

void charSleep(character_t *character);

void stats(character_t *character);

void endScreen(character_t* character, world_t* world);
