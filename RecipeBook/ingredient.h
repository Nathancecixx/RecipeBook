#pragma once
#define _CRT_SECURE_NO_WARNINGS
typedef enum { WEIGHT, VOLUME }MEASUREMENT_TYPE;

typedef struct ingredient {
    int num;
    char name[25];
}INGREDIENT, PINGREDIENT;

INGREDIENT CreateIngredient(int Num, char* Name);

void DisplayIngredient(INGREDIENT ingredient);

void DestroyIngredient(INGREDIENT* ingredient);

char* getIngredient(INGREDIENT);