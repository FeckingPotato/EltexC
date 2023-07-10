#include "character.h"
#include <malloc.h>
#include <string.h>

character_t initCharacter(char* name, unsigned int raceID) {
    character_t * character = (character_t*) malloc(sizeof(character_t));
    character->name = (char*) malloc(strlen(name)+1);
    strcpy(character->name, name);
    character->raceID = raceID;
    character->hp = MAX_HP;
    character->xp = 0;
    character->money = 0;
    character->stats = statPresets[raceID];
    return *character;
}