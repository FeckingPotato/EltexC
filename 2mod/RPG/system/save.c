#include "save.h"
#include <stdio.h>
#include <string.h>

int save(char* path, character_t* character, world_t* world) {
    FILE *file = NULL;
    file = fopen(path, "w");
    if (file == NULL) {
        return 1;
    }
    if (
            fwrite(character->name, 1, strlen(character->name)+1, file) ||
            fwrite(character, sizeof(character_t), 1, file) ||
            fwrite(world, sizeof(world_t), 1, file)
            ) {
        fclose(file);
        return 2;
    }
    fclose(file);
    return 0;
}

int load(char* path, character_t* character, world_t* world) {
    FILE *file = NULL;
    file = fopen(path, "r");
    if (file == NULL) {
        return 1;
    }
    if (fread(character, sizeof(character_t), 1, file)) {
        fclose(file);
        return 2;
    }
    if (fread(world, sizeof(world_t), 1, file)) {
        fclose(file);
        return 2;
    }
    fclose(file);
    return 0;
}
