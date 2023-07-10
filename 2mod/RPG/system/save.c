#include "save.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int save(char* path, character_t* character, world_t* world) {
    FILE *file = NULL;
    file = fopen(path, "w");
    if (file == NULL) {
        return 1;
    }
    fwrite(character, sizeof(character_t)-sizeof(char *), 1, file);
    fwrite(character->name, 1, strlen(character->name)+1, file);
    fwrite(world, sizeof(world_t), 1, file);
    fclose(file);
    return 0;
}

int load(char* path, character_t* character, world_t* world) {
    FILE *file = NULL;
    file = fopen(path, "r");
    if (file == NULL) {
        return 1;
    }
    fread(character, sizeof(character_t)-sizeof(char *), 1, file);
    char name[64];
    fgets(name, 64, file);
    character->name = malloc(strlen(name)+1);
    strcpy(character->name, name);
    fread(world, sizeof(world_t), 1, file);
    fclose(file);
    return 0;
}
