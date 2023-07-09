#include "tree.h"
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif


int main() {
    time_t t;
    srand((unsigned) time(&t));
    tree_t* tree = (tree_t*) malloc(sizeof(tree_t));
    bool bootDone = false;
    while (true) {
        if (bootDone) {
            printf("Press any key to continue.");
            getchar();
        }
        system(CLEAR);
        bootDone = true;
        printf("Current tree size: %u\n"
               "1. Add an element to the tree\n"
               "2. Add random elements to the tree\n"
               "3. Print the tree\n"
               "0. Exit \n"
               "Command: ", tree->size);
        char option = fgetc(stdin);
        stdin->_IO_read_ptr = stdin->_IO_buf_end;
        char input[32];
        int number;
        switch (option) {
            default:
                printf("Wrong option.\n");
                break;
            case '1':
                printf("Input the number to add: ");
                fgets(input, 32, stdin);
                int number = strtol(input, NULL, 10);
                push(number, tree);
                printf("Added %d\n", number);
                break;
            case '2':
                printf("Input the amount of numbers to add: ");
                fgets(input, 32, stdin);
                unsigned int amount = strtoul(input, NULL, 10);
                pushRand(amount, tree);
                printf("Added %u random numbers to the tree\n", amount);
                break;
            case '3':
                printTree(tree);
                break;
            case '0':
                return 0;
        }
    }
}