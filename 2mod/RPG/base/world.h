#pragma once
typedef struct {
    unsigned int day;
    unsigned int location; //0 - town, 1 - road event, 2 - adventure
    unsigned int locID; // used for road events and adventure types
    bool bossUnlocked;
} world_t;

world_t initWorld();