#include "character.h"
#include "../system/utils.h"
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

charAttack_t attackEnemy(enemy_t *enemy, character_t *character, unsigned int definedD6) {
    charAttack_t attack;
    if (definedD6 > 0) {
        attack.d6[0] = definedD6;
    }
    else {
        attack.d6[0] = d6();
    }
    attack.d6[1] = d6();
    attack.damage = character->stats.strength;
    if (character->stats.intelligence >= d20()) {
        attack.crit = true;
        attack.damage += attack.damage/2;
    }
    unsigned int skillCheck = attack.d6[0] + attack.d6[1];
    attack.damage += skillCheck/2;
    return attack;
}

bool receiveDamageChar(unsigned int damage, character_t *character) {
    if (damage >= character->hp) {
        return true;
    }
    character->hp -= damage;
    return false;
}

int attackChar(character_t *character, enemy_t* enemy) {
    unsigned int skillCheck = d6() + d6();
    if (skillCheck < character->stats.dexterity) {
        return -1;
    }
    skillCheck = d6() + d6();
    return skillCheck/2 + enemy->damage;
}

bool receiveDamageEnemy(unsigned int damage, enemy_t* enemy) {
    if (damage >= enemy->hp) {
        return true;
    }
    enemy->hp -= damage;
    return false;
}
