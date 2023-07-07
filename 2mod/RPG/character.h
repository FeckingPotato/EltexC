#include "items.h"

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
    char* name;
    unsigned int raceID;
    unsigned int hp;
    unsigned int xp;
    unsigned int money;
    stats_t stats;
    ultimate_t ultimate;
    item_t* items;
    item_t* equippedItems[5]; // 0 - head, 1 - chest, 2 - legs, 3 - left hand, 4 - right hand
} character_t;

static char* races[3] = {"a human", "an orc", "an elf"};

static stats_t statPresets[3] = {
        {.strength = 5, .strengthCap = 10, .dexterity = 5, .dexterityCap = 10, .intelligence = 5, .intelligenceCap = 10},
        {.strength = 8, .strengthCap = 15, .dexterity = 5, .dexterityCap = 10, .intelligence = 4, .intelligenceCap = 6},
        {.strength = 4, .strengthCap = 6, .dexterity = 8, .dexterityCap = 15, .intelligence = 5, .intelligenceCap = 10},
};

static ultimate_t ultPresets[3] = {
        {.name = "Human ult", .statID = 4, .buff = 2}, // 4 - every stat
        {.name = "Orc ult", .statID = 2, .buff = 4},
        {.name = "Elf ult", .statID = 0, .buff = 4}
};

character_t initCharacter(char* name, unsigned int raceID);
