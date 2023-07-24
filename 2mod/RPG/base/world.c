#include "world.h"
#include <malloc.h>

world_t initWorld() {
    world_t* world = (world_t*) malloc(sizeof(world_t));
    world->day = 1;
    world->bossUnlocked = false;
    return *world;
}