#pragma once
#define HEALING_COUNT 3

typedef struct {
    char* name;
    unsigned int price;
    unsigned int healingAmount;
} healing_t;

static const healing_t potions[HEALING_COUNT] = {
    {.name = "Small healing potion", .price = 5, .healingAmount = 5},
    {.name = "Medium healing potion", .price = 10, .healingAmount = 8},
    {.name = "Large healing potion", .price = 15, .healingAmount = 12   }
};
