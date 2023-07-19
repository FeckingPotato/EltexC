#include "beakers.h"
#include <stdio.h>

int main() {
    beaker_t beakers[3];
    unsigned int R;
    printf("A beaker volume: ");
    scanf("%u", &(beakers[0].max));
    if (beakers[0].max == 0) {
        printf("The volume should be more than 0");
        return 0;
    }
    printf("B beaker volume: ");
    scanf("%u", &(beakers[1].max));
    if (beakers[1].max == 0) {
        printf("The volume should be more than 0");
        return 0;
    }
    printf("C beaker volume: ");
    scanf("%u", &(beakers[2].max));
    if (beakers[2].max == 0) {
        printf("The volume should be more than 0");
        return 0;
    }
    printf("(R)equired volume: ");
    scanf("%u", &R);
    if (R == 0) {
        printf("The volume should be more than 0");
        return 0;
    }
    if (initBeakers(beakers) == 1) {
        printf("The beakers volumes should not be equal");
        return 0;
    }
    if (R > beakers[0].max) {
        printf("The required volume should be less or equal to the max volume of beakers");
        return 0;
    }
    printf("Starting with the medium sized beaker:\n");
    unsigned int steps1 = solve1(beakers, R);
    printf("Final liquid distribution in the beakers:\n"
           "1. %d/%d\n"
           "2. %d/%d\n"
           "3. %d/%d\n",
           beakers[0].current, beakers[0].max,
           beakers[1].current, beakers[1].max,
           beakers[2].current, beakers[2].max);
    printf("Took %u steps\n", steps1);
    initBeakers(beakers);
    printf("\n");
    printf("Starting with the small sized beaker:\n");
    unsigned int steps2 = solve2(beakers, R);
    printf("Final liquid distribution in the beakers:\n"
           "1. %d/%d\n"
           "2. %d/%d\n"
           "3. %d/%d\n",
           beakers[0].current, beakers[0].max,
           beakers[1].current, beakers[1].max,
           beakers[2].current, beakers[2].max);
    printf("Took %u steps\n", steps2);
    printf("\n");
    if (steps1 < steps2) {
        printf("The first method is more efficient\n");
    }
    else if (steps2 < steps1) {
        printf("The second method is more efficient\n");
    }
    else {
        printf("The methods are equally efficient\n");
    }
    return 0;
}
