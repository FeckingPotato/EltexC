#pragma once

#include "../base/character.h"

typedef struct {
    char* name;
    unsigned int hp;
    unsigned int hpMax;
    unsigned int damage;
    unsigned int resistance;
} enemy_t;

static const enemy_t enemies[] = {
        //enemy presets
};

int attackChar(character_t *character, enemy_t* enemy);

bool receiveDamageEnemy(unsigned int damage, enemy_t* enemy);
