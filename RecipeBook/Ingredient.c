#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ingredient.h"

INGREDIENT CreateIngredient(int Num, char* Name) {
    INGREDIENT ingredient;

    ingredient.num = Num;
    strncpy(ingredient.name, Name, 25);

    return ingredient;
}


void DisplayIngredient(INGREDIENT ingredient) {
    printf("        %s\n", ingredient.name);
}

void DestroyIngredient(INGREDIENT* ingredient) {
    free(ingredient);
}