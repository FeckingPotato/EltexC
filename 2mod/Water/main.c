#include <stdio.h>

typedef struct {
    unsigned int max;
    unsigned int current;
} beaker_t;

char initBeakers(beaker_t beakers[3]) {
    for (char i = 0; i < 3; i++) {
        unsigned char first = i % 3;
        unsigned char second = (i + 1) % 3;
        if (beakers[first].max == beakers[second].max) {
            return 1;
        }
        if (beakers[first].max > beakers[second].max) {
            unsigned int temp;
            temp = beakers[first].max;
            beakers[first].max = beakers[second].max;
            beakers[second].max = temp;
        }
    }
    beakers[0].current = beakers[0].max;
    beakers[1].current = 0;
    beakers[2].current = 0;
    return 0;
}

void pour(beaker_t* from, beaker_t* to) {
    unsigned int amount = to->max - to->current;
    if (from->current < amount) {
        amount = from->current;
    }
    from->current -= amount;
    to->current += amount;
}

void solve(beaker_t beakers[3], unsigned int R) {
    while (beakers[0].current != R) {
        while (beakers[2].current == 0) {
            pour(&beakers[0], &beakers[2]);
            pour(&beakers[2], &beakers[1]);
        }
        pour(&beakers[1], &beakers[0]);
        pour(&beakers[2], &beakers[1]);
        pour(&beakers[0], &beakers[2]);
    }
}

int main() {
    beaker_t beakers[3];
    unsigned int R;
    beakers[0].max = 8;
    beakers[1].max = 3;
    beakers[2].max = 5;
    R = 4;
    /* printf("A beaker volume: ");
    scanf("%ud", &(beakers[0].max));
    if (beakers[0].max == 0) {
        printf("The volume should be more than 0");
        return 0;
    }
    printf("B beaker volume: ");
    scanf("%ud", &(beakers[1].max));
    if (beakers[1].max == 0) {
        printf("The volume should be more than 0");
        return 0;
    }
    printf("C beaker volume: ");
    scanf("%ud", &(beakers[2].max));
    if (beakers[2].max == 0) {
        printf("The volume should be more than 0");
        return 0;
    }
    printf("(R)equired volume: ");
    scanf("%ud", &R);
    if (R == 0) {
        printf("The volume should be more than 0");
        return 0;
    }*/
    if (initBeakers(beakers) == 1) {
        printf("The beakers volumes should not be equal");
        return 0;
    }
    if (R > beakers[0].max) {
        printf("The required volume should be less or equal to the max volume of beakers");
        return 0;
    }
    solve(beakers, R);
    return 0;
}
