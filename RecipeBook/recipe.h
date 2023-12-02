#pragma once

#include <string.h>
#include <stdbool.h>
#include "listnode.h"

typedef struct recipe {
    int numberOfSteps;
    char name[25];
    PLISTNODE ingredientHead;
    PLISTNODE stepHead;
}RECIPE;


RECIPE CreateRecipe(int NumberOfSteps, char* Name);

bool AddIngredientToRecipe(RECIPE* recipe, int Num, char* Name);

bool CompareRecipe(RECIPE LH, RECIPE RH);

RECIPE CopyRecipe(RECIPE recipe);