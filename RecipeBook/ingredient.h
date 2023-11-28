#pragma once

typedef struct ingredient {
    int Num;
    char name[25];
}INGREDIENT;

INGREDIENT CreateIngredient(int Num, char* name);

int GetIngredientNum(INGREDIENT ingredient);
char* GetIngredientName(INGREDIENT ingredient);

INGREDIENT CopyIngredient(INGREDIENT ingredient);