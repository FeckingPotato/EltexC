#include "beakers.h"
#include <stdio.h>

int initBeakers(beaker_t beakers[3]) {
    if (beakers[0].max == beakers[1].max || beakers[0].max == beakers[2].max || beakers[1].max == beakers[2].max) {
        return 1;
    }
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (beakers[j].max < beakers[j+1].max) {
                unsigned int temp;
                temp = beakers[j].max;
                beakers[j].max = beakers[j+1].max;
                beakers[j+1].max = temp;
            }
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
        printf("Poured from %d/%d beaker to %d/%d beaker\n",
               beakers[0].current, beakers[0].max, beakers[1].current, beakers[1].max);
        pour(&beakers[0], &beakers[1]);
        while (beakers[1].current != 0){
            printf("Poured from %d/%d beaker to %d/%d beaker\n",
                   beakers[1].current, beakers[1].max, beakers[2].current, beakers[2].max);
            pour(&beakers[1], &beakers[2]);
            if (beakers[1].current == 0) {
                break;
            }
            printf("Poured from %d/%d beaker to %d/%d beaker\n",
                   beakers[2].current, beakers[2].max, beakers[0].current, beakers[0].max);
            pour(&beakers[2], &beakers[0]);
            if (beakers[0].current == R) {
                return;
            }
        }
    }
}