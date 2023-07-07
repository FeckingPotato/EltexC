#include "world.h"
#include <malloc.h>

world_t initWorld() {
    world_t* world = (world_t*) malloc(sizeof(world_t));
    world->day = 0;
    world->location = 0;
    world->locID = 0;
    world->bossUnlocked = false;
    return *world;
}