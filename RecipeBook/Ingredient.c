#include <string.h>
#include <stdlib.h>
#include "ingredient.h"


INGREDIENT CreateIngredient(int Num, char* Name) {
    INGREDIENT ingredient;

    ingredient.Num = Num;
    strncpy(ingredient.name, Name, 25);

    return ingredient;
}

int GetIngredientNum(INGREDIENT ingredient) {
    return ingredient.Num;
}
char* GetIngredientName(INGREDIENT ingredient) {
    return ingredient.name;
}

INGREDIENT CopyIngredient(INGREDIENT ingredient) {
    INGREDIENT i;
    
    i.Num = ingredient.Num;
    strncpy(i.name, ingredient.name, 25);

    return i;
}