#include "ui.h"
#include "utils.h"
#include <stdio.h>
#include <assert.h>

void printSkills(character_t* character) {
    printf("%s's skills are:\n"
           "Strength: %u/%u\n"
           "Dexterity: %u/%u\n"
           "Intelligence: %u/%u\n",
           character->name,
           character->stats.strength, character->stats.strengthCap,
           character->stats.dexterity, character->stats.dexterityCap,
           character->stats.intelligence, character->stats.intelligenceCap);
}

int incrementSkill(unsigned int increment, unsigned int* points, unsigned int* skill, const unsigned int* cap) {
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
    stats_t newStats = character->stats;
    printf("Raise strength by: ");
    int increment = getDigit();
    if (incrementSkill(increment, &points, &newStats.strength, &newStats.strengthCap) != 0) {
        return 1;
    }
    printf("Raise dexterity by: ");
    increment = getDigit();
    if (incrementSkill(increment, &points, &newStats.dexterity, &newStats.dexterityCap) != 0) {
        return 1;
    }
    printf("Raise intelligence by: ");
    increment = getDigit();
    if (incrementSkill(increment, &points, &newStats.intelligence, &newStats.intelligenceCap) != 0) {
        return 1;
    }
    if (points != 0) {
        printf("Incorrect distribution of points, try again\n");
        return 1;
    }
    character->stats = newStats;
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
           racesArticles[character->raceID],
           character->name);
    clearOutput(true);
    int result = 1;
    while(result != 0) {
        result = levelUp(5, character);
        clearOutput(true);
    }
}

int mainMenu(world_t *world) {
    while (true) {
        printf("Day %u\n"
               "You are now in the town, your options are:\n"
               "1. Seek an adventure\n"
               "2. Buy healing potions\n",
               world->day);
        if (world->bossUnlocked) {
            printf("3. Attempt fighting the final boss\n");
        }
        else {
            printf("3. Ask around about the final boss\n");
        }
        printf("4. Sleep (skips the day, restores HP)\n"
               "5. Look at your stats\n"
               "0. Exit\n"
               "Pick your option: ");
        int option = getDigit();
        if (option < 0 || option > 5) {
            printf("Wrong option, try again\n");
            clearOutput(true);
            continue;
        }
        return option;
    }
}

bool fight(character_t *character) {
    unsigned int die = 0;
    bool rerolled = false;
    enemy_t enemy = enemies[d6() % ENEMY_COUNT];
    while (true) {
        printf("You encounter a %s\n"
               "His stats:\n"
               "HP: %d/%d\n"
               "Damage: %d\n"
               "\n"
               "1. Attack\n"
               "2. Use potion\n"
               "3. Escape\n"
               "Your choice: ", enemy.name, enemy.hp, enemy.hpMax, enemy.damage);
        int input = getDigit();
        if (input == 1) {
            charAttack_t charAttack;
            while (true) {
                charAttack = attackEnemy(character, die);
                die = 0;
                printf("You roll %d and %d attack modifiers (%d in total) \n"
                       "You deal %d damage\n",
                       charAttack.d6[0], charAttack.d6[1], (charAttack.d6[0] + charAttack.d6[1])/2, charAttack.damage);
                if (charAttack.crit) {
                    printf("You deal critical damage\n");
                }
                printf("\n");
                if (!rerolled) {
                    printf("You can reroll one of your dice\n"
                           "Input the number of the dice to reroll (1/2) or anything else to skip: ");
                    int newDie = getDigit();
                    if (newDie == 1 || newDie == 0) {
                        die = newDie;
                        rerolled = true;
                        clearOutput(false);
                        continue;
                    }
                }
                break;
            }
            if (receiveDamageEnemy(charAttack.damage, &enemy)) {
                printf("You have defeated the enemy, your reward is:\n"
                       "XP: %d\n"
                       "Money: %d\n", enemy.xp, enemy.money);
                character->xp += enemy.xp;
                character->money += enemy.money;
                return false;
            }
            int enemyAttack = attackChar(character, &enemy);
            if (enemyAttack == -1) {
                printf("You have dodged the attack\n");
            }
            else {
                printf("You have received %d damage\n", enemyAttack);
                if (receiveDamageChar(enemyAttack, character)) {
                    printf("You have died\n");
                    return true;
                }
            }
        }
        else if (input == 2) {
            // JFC THERE IS SO MUCH MORE TO DO
        }
        else if (input == 3) {
            printf("You have deserted\n");
            return false;
        }
        else {
            printf("Wrong option, try again\n");
        }
        clearOutput(true);
    }
}

void shop(character_t *character) {
    while (true) {
        printf("You enter the shop. You can buy:\n");
        for (unsigned int i = 0; i < HEALING_COUNT; i++) {
            printf("%u. %s (heals %u HP, costs %u coins)\n",
                   i+1, potions[i].name, potions[i].healingAmount, potions[i].price);
        }
        printf("Pick option (type in 0 to exit the shop)\n");
        int option = getDigit(); // this will break if there are >9 healing items
        if (option < 0 || option > HEALING_COUNT) {
            printf("Wrong option, try again\n");
            clearOutput(true);
            continue;
        }
        if (option == 0) {
            printf("You leave the shop");
            break;
        }
        option--;
        if (potions[option].price > character->money) {
            printf("You don't have enough money.\n");
            clearOutput(true);
            continue;
        }
        unsigned int freeSlot = 0;
        bool notFree = true;
        while (freeSlot < HEALING_CAPACITY) {
            if (character->healingItems[freeSlot].name == NULL) {
                notFree = false;
                break;
            }
            freeSlot++;
        }
        if (notFree) {
            printf("You don't have a free slot for the item.\n");
            clearOutput(true);
            continue;
        }
        character->money -= potions[option].price;
        character->healingItems[freeSlot] = potions[option];
        printf("You bought %s.\n", potions[option].name);
        clearOutput(true);
    }
}

bool boss(character_t* character, world_t* world) {
    if (character->xp / XP_PER_LEVEL < 5) {
        printf("You try asking around about the whereabouts of the boss, but you are not notorious enough for anyone to tell you.\n"
               "Try again when you reach the 5th level.\n");
        return false;
    }
    if (!world->bossUnlocked) {
        printf("You manage to make people tell you the location of the final boss. You can now fight him.\n");
        world->bossUnlocked = true;
        return false;
    }
    printf("The final boss fight is not done yet, so you defeat him easily.\n");
    return true;
}

void charSleep(character_t *character) {
    printf("You fall asleep\n"
           "HP restored\n");
    character->hp = MAX_HP;
}

void stats(character_t *character) {
    printf("%s's stats are:\n"
           "Race: %s\n"
           "Level: %u (%u XP left until the next level)\n"
           "Money: %u coins\n",
           character->name,
           races[character->raceID],
           character->xp / XP_PER_LEVEL, XP_PER_LEVEL - character->xp % XP_PER_LEVEL,
           character->money);
    printSkills(character);
}

void endScreen(character_t* character, world_t* world) {
    assert(false && "Not implemented");
}