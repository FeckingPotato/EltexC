#include "ui.h"
#include "utils.h"
#include <stdio.h>

void printSkills(character_t* character) {
    printf("Your skills are:\n"
           "Strength: %u/%u\n"
           "Dexterity: %u/%u\n"
           "Intelligence: %u/%u\n",
           character->stats.strength, character->stats.strengthCap,
           character->stats.dexterity, character->stats.dexterityCap,
           character->stats.intelligence, character->stats.intelligenceCap);
}

int incrementSkill(unsigned int increment, unsigned int* points, unsigned int* skill, unsigned int* cap) {
    if (increment < 0 || increment > *points) {
        printf("Wrong amount of points, try again\n");
        return 1;
    }
    if (increment > *cap - *skill) {
        printf("The amount of points will exceed the cap, try again\n");
        return 1;
    }
    *skill += increment;
    *points -= increment;
    return 0;
}

int levelUp(unsigned int points, character_t* character) {
    printf("You have %u skill points to spend.", points);
    printSkills(character);
    printf("Raise strength by: ");
    int increment = getDigit();
    if (incrementSkill(increment, &points, &character->stats.strength, &character->stats.strengthCap) != 0) {
        return 1;
    }
    printf("Raise dexterity by: ");
    increment = getDigit();
    if (incrementSkill(increment, &points, &character->stats.dexterity, &character->stats.dexterityCap) != 0) {
        return 1;
    }
    printf("Raise intelligence by: ");
    increment = getDigit();
    if (incrementSkill(increment, &points, &character->stats.intelligence, &character->stats.intelligenceCap) != 0) {
        return 1;
    }
    if (points != 0) {
        printf("Incorrect distribution of points, try again\n");
        return 1;
    }
    return 0;
}

void init(character_t* character, world_t* world) {
    char name[64];
    printf("What is your name?\n"
           "My name is: ");
    fgets(name, 64, stdin);
    removeNL(name);
    printf("Available races:\n"
           "1. Human\n"
           "2. Orc\n"
           "3. Elf\n"
           "Pick your race: ");
    int race = getDigit();
    if (race < 1 || race > 3) {
        printf("Unknown race, defaulting to human.\n");
        race = 1;
    }
    *character = initCharacter(name, race-1);
    *world = initWorld();
    printf("You are %s called %s. You live in a town called Darkhaven. You have to defeat the worst guy. But first you need to obtain a huge level.\n",
           races[character->raceID],
           character->name);
    clearOutput(true);
    int result = 1;
    while(result != 0) {
        result = levelUp(5, character);
        clearOutput(true);
    }
}
