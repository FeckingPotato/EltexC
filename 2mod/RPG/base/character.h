#pragma once

#include "../adventures/enemy.h"
#include "../items/healing.h"


#define MAX_HP 50
#define XP_PER_LEVEL 20
#define HEALING_CAPACITY 5

typedef struct {
    unsigned int strength; // 0
    unsigned int strengthCap;
    unsigned int dexterity; // 1
    unsigned int dexterityCap;
    unsigned int intelligence; // 2
    unsigned int intelligenceCap;

} stats_t;

typedef struct {
    healing_t healingItems[HEALING_CAPACITY];
    unsigned int raceID;
    unsigned int hp;
    unsigned int xp;
    unsigned int money;
    stats_t stats;
    char* name;

} character_t;

typedef struct {
    bool crit;
    unsigned int d6[2];
    unsigned int damage;
} charAttack_t;

static const char* racesArticles[3] = {"a human", "an orc", "an elf"};

static const char* races[3] = {"human", "orc", "elf"};

static const stats_t statPresets[3] = {
        {.strength = 5, .strengthCap = 10, .dexterity = 5, .dexterityCap = 10, .intelligence = 5, .intelligenceCap = 10},
        {.strength = 8, .strengthCap = 15, .dexterity = 5, .dexterityCap = 10, .intelligence = 4, .intelligenceCap = 6},
        {.strength = 4, .strengthCap = 6, .dexterity = 8, .dexterityCap = 15, .intelligence = 5, .intelligenceCap = 10},
};

character_t initCharacter(char* name, unsigned int raceID);

charAttack_t attackEnemy(character_t *character, unsigned int definedD6);

bool receiveDamageChar(unsigned int damage, character_t *character);

int attackChar(character_t *character, enemy_t* enemy);

bool receiveDamageEnemy(unsigned int damage, enemy_t* enemy);
