#include "system/utils.h"
#include "system/ui.h"
#include "system/save.h"
#include <stdio.h>

character_t character;
world_t world;

int main() {
    init(&character, &world);
    bool finished = false;
    while (!finished) {
        switch (save("save.sv", &character, &world) == 1) {
            case 1:
                printf("WARNING: Save failed. Unable to open the save file.\n");
                break;
            case 2:
                printf("WARNING: Save faled. Unable to write to the save file.\n");
                break;
        }
        switch (mainMenu(&character, &world)) {
            case 0:
                //exit
                return 0;
            case 1:
                adventure(&character, &world);
                break;
            case 2:
                shop(&character, &world);
                break;
            case 3:
                boss(&character, &world);
                break;
            case 4:
                sleep(&character, &world);
                break;
            case 5:
                stats(&character, &world);
                break;
        }
    }
}
