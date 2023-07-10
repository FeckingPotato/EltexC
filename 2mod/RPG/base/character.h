#pragma once
#include "../items/equipment.h"
#include "../items/healing.h"

#define MAX_HP 50

typedef struct {
    unsigned int strength; // 0
    unsigned int strengthCap;
    unsigned int dexterity; // 1
    unsigned int dexterityCap;
    unsigned int intelligence; // 2
    unsigned int intelligenceCap;

} stats_t;

typedef struct {
    char* name;
    int statID;
    int buff;
    bool used;
} ultimate_t;

typedef struct {
    healing_t healingItems[5];
    equipment_t equipment[5]; // 0 - head, 1 - chest, 2 - legs, 3 - left hand, 4 - right hand
    unsigned int raceID;
    unsigned int hp;
    unsigned int xp;
    unsigned int money;
    stats_t stats;
    char* name;

} character_t;

static const char* races[3] = {"a human", "an orc", "an elf"};

static const stats_t statPresets[3] = {
        {.strength = 5, .strengthCap = 10, .dexterity = 5, .dexterityCap = 10, .intelligence = 5, .intelligenceCap = 10},
        {.strength = 8, .strengthCap = 15, .dexterity = 5, .dexterityCap = 10, .intelligence = 4, .intelligenceCap = 6},
        {.strength = 4, .strengthCap = 6, .dexterity = 8, .dexterityCap = 15, .intelligence = 5, .intelligenceCap = 10},
};

character_t initCharacter(char* name, unsigned int raceID);
