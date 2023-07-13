#pragma once
typedef struct {
    unsigned int day;
    bool bossUnlocked;
} world_t;

world_t initWorld();

void advanceDay(world_t* world);
