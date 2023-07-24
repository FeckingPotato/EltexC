#include "system/utils.h"
#include "system/ui.h"
#include "system/save.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

character_t character;
world_t world;

int main() {
    srand(time(NULL));
    if (access("save.sv", F_OK) == 0) {
        load("save.sv", &character, &world);
    }
    else {
        init(&character, &world);
    }
    while (!world.finished) {
        if (save("save.sv", &character, &world) != 0) {
            printf("ERROR: Save failed. Unable to open the save file.\n");
        }
        switch (mainMenu(&world)) {
            case 0:
                //exit
                return 0;
            case 1:
                clearOutput(false);
                world.finished = fight(&character);
                if (world.finished) {
                    world.dead = true;
                }
                else {
                    world.day++;
                }
                break;
            case 2:
                clearOutput(false);
                shop(&character);
                break;
            case 3:
                clearOutput(false);
                world.finished = boss(&character, &world);
                break;
            case 4:
                clearOutput(false);
                charSleep(&character);
                world.day++;
                break;
            case 5:
                clearOutput(false);
                stats(&character);
                break;
        }
        clearOutput(true);
    }
    endScreen(&character, &world);
}
