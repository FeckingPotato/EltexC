#include "enemy.h"
#include "../system/utils.h"

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