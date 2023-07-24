#pragma once

#define ENEMY_COUNT 1

typedef struct {
    char* name;
    unsigned int hp;
    unsigned int hpMax;
    unsigned int damage;
    unsigned int xp;
    unsigned int money;
} enemy_t;

static const enemy_t enemies[ENEMY_COUNT] = {
        {.name = "bad guy", .hpMax = 10, .hp = 10, .damage = 1, .xp = 10, .money = 10}
};
