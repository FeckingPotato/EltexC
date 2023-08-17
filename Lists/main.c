#include "list.h"
#include "argParse.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define INPUT_SIZE 32

int main() {
    time_t t;
    srand((unsigned) time(&t));
    list_t* list = (list_t*) malloc(sizeof(list_t));
    bool bootDone = false;
    char input[INPUT_SIZE];
    while (true) {
        if (bootDone) {
            printf("Press any key to continue.");
            getchar();
        }
        system(CLEAR);
        bootDone = true;
        printf("Current list: ");
        printList(list, false);
        printf("1. Add element to list\n"
               "2. Remove element from list\n"
               "3. Get element's value\n"
               "4. Set element's value\n"
               "5. Print reverse list\n"
               "6. Add random numbers to list\n"
               "7. Sort, ascending order (bubble)\n"
               "8. Sort,  descending order (comb)\n"
               "9. Clear list\n"
               "0. Exit\n"
               "Options 1, 2, 3 use those modifiers:\n"
               "a - head (default)\n"
               "b - tail\n"
               "c - by element's index\n"
               "Command example: 1, 2a, 3cINDEX, 4b\n"
               "\n"
               "Command: ");
        fgets(input, INPUT_SIZE, stdin);
        args_t arguments = argParse(input, list->length);
        if (arguments.option < 0 || arguments.option > 9) {
            printf("Error: ");
            switch(arguments.option) {
                default:
                    printf("Unknown error\n");
                    break;
                case -1:
                    printf("No spaces allowed\n");
                    break;
                case -2:
                    printf("Unknown argument\n");
                    break;
                case -3:
                    printf("The command doesn't support modifiers\n");
                    break;
                case -4:
                    printf("Unknown modifier\n");
                    break;
                case -5:
                    printf("The modifier doesn't support index\n");
                    break;
                case -6:
                    printf("The modifier requires index\n");
                    break;
                case -7:
                    printf("Index out of bounds\n");
                    break;
            }
            continue;
        }
        unsigned int index = 0;
        if (arguments.option <= 4) {
            switch (arguments.modifier) {
                case 'b':
                    index = list->length;
                    if (arguments.option != 1) {
                        index--;
                    }
                    break;
                case 'c':
                    index = arguments.index;
                    break;
            }
        }
        switch (arguments.option) {
            case 0:
                return 0;
            case 1: {
                printf("Type in the number to insert: ");
                fgets(input, INPUT_SIZE, stdin);
                int number = (int) strtol(input, NULL, 10);
                pushInd(number, index, list);
                printf("Added %d to the list\n", number);
                break;
            }
            case 2: {
                int number = getValueInd(index, list);
                removeInd(index, list);
                printf("Removed %d from the list\n", number);
                break;
            }
            case 3: {
                int number = getValueInd(index, list);
                printf("The element's value is %d\n", number);
                break;
            }
            case 4: {
                printf("Type in the new value: ");
                fgets(input, INPUT_SIZE, stdin);
                int oldNumber = getValueInd(index, list);
                int newNumber = (int) strtol(input, NULL, 10);
                setValueInd(newNumber, index, list);
                printf("Replaced %d with %d\n", oldNumber, newNumber);
                break;
            }
            case 5:
                printList(list, true);
                break;
            case 6: {
                printf("Type in the amount of random numbers: ");
                fgets(input, INPUT_SIZE, stdin);
                unsigned int amount = (unsigned int) strtoul(input, NULL, 10);
                randFill(amount, list);
                printf("Added %d random numbers to the list\n", amount);
                break;
            }
            case 7:
                sortAsc(list);
                printf("Sorted (asc)\n");
                break;
            case 8:
                sortDesc(list);
                printf("Sorted (desc)\n");
                break;
            case 9: {
                printf("This will WIPE THE ENTIRE LIST. To continue type in the phrase 'Yes, do as I say!'\n");
                fgets(input, INPUT_SIZE, stdin);
                if (strcmp(input, "Yes, do as I say!\n") == 0) {
                    wipeList(list);
                    printf("The list was wiped\n");
                    continue;
                }
                printf("Aborting\n");
            }
        }
    }
}
