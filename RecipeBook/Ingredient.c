#include "ingredient.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


INGREDIENT CreateIngredient(int Num, char* Name) {
    INGREDIENT ingredient;

    ingredient.num = Num;
    strncpy(ingredient.name, Name, 25);

    return ingredient;
}

void DestroyIngredient(INGREDIENT* ingredient) {
    free(ingredient);
}

char* getIngredient(INGREDIENT ingredient)
{
    return ingredient.name;
}
