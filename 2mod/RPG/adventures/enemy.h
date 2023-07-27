#pragma once

#define ENEMY_COUNT 3

typedef struct {
    char* name;
    unsigned int hp;
    unsigned int hpMax;
    unsigned int damage;
    unsigned int xp;
    unsigned int money;
} enemy_t;

static const enemy_t enemies[ENEMY_COUNT] = {
        {.name = "a goblin", .hpMax = 20, .hp = 20, .damage = 3, .xp = 10, .money = 10},
        {.name = "a troll", .hpMax = 30, .hp = 30, .damage = 5, .xp = 15, .money = 15},
        {.name = "an evil spirit", .hpMax = 15, .hp = 10, .damage = 10, .xp = 20, .money = 20},
};

static const enemy_t boss = {.name = "Kaya", .hpMax = 50, .hp = 50, .damage = 8, .xp = 0, .money = 0};
