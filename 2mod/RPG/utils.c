#include "utils.h"
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

unsigned int d6() {
    srand(time(NULL));
    return rand() % 6 + 1;
}

unsigned int d20() {
    srand(time(NULL));
    return rand() % 20 + 1;
}

int clamp(int value, int min, int max) {
    if (value >= max) {
        return max;
    }
    if (value <= min) {
        return min;
    }
    return value;
}

void clearStdin() {
    stdin->_IO_read_ptr = stdin->_IO_read_end;
}

int getDigit() {
    clearStdin();
    char input = getc(stdin);
    if (!isdigit(input)) {
        return -1;
    }
    return input - '0';
}

void clearOutput(bool anykey) {
    if (anykey) {
        printf("Press any key to continue.");
        clearStdin();
        fgetc(stdin);
    }
    system(CLEAR);
}

void removeNL(char* string) {
    while(*string != '\n') {
        string++;
    }
    *string = '\0';
}