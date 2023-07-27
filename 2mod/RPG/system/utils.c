#include "utils.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

unsigned int d6() {
    return rand() % 6 + 1;
}

unsigned int d20() {
    return rand() % 20 + 1;
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
        printf("Type in anything to continue.");
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