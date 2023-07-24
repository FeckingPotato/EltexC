#pragma once
typedef struct {
    unsigned int day;
    bool bossUnlocked;
    bool finished;
    bool dead;
} world_t;

world_t initWorld();
