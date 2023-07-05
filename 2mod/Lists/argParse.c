#include "argParse.h"
#include <stdlib.h>
#include <ctype.h>

bool checkSpace(char input[]) {
    char* curChar = input;
    while (*curChar != '\n') {
        if (*curChar == ' ') {
            return true;
        }
        curChar++;
    }
    return false;
}

args_t argParse(char input[], unsigned int length) {
    args_t result;
    if (checkSpace(input)) {
        result.option = -1;
        return result;
    }
    if (!isdigit(input[0])) {
        result.option = -2;
        return result;
    }
    int option = input[0] - '0';
    if (option > 9) {
        result.option = -2;
        return result;
    }
    if (option > 4 && input[1] != '\n') {
        result.option = -3;
        return result;
    }
    result.option = option;
    result.modifier = input[1];
    if (option > 4 || input[1] == '\n') {
        return result;
    }
    if (!(input[1] == 'a' || input[1] == 'b' || input[1] == 'c' || input[1] == '\n')) {
        result.option = -4;
        return result;
    }
    if (input [1] != 'c' && input[2] != '\n' && input[1]) {
        result.option = -5;
        return result;
    }
    if (result.modifier == 'c') {
        char* number = &(input[2]);
        char* endptr;
        unsigned int index = (unsigned int) strtoul(number, &endptr, 10);
        if (number == endptr) {
            result.option = -6;
            return result;
        }
        if (result.option == 1 && index > length) {
            result.option = -7;
            return result;
        }
        if (index >= length) {
            result.option = -7;
            return result;
        }
        result.index = index;
    }
    return result;
}
