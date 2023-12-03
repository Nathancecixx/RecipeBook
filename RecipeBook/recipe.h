#pragma once

#include <stdbool.h>
#include "ingredient.h"
#include "step.h"

#define MAX_RECIPE_NAME       25

typedef struct recipe {
    char name[MAX_RECIPE_NAME];
    INGREDIENT* ingredientList;
    STEP* stepList;
}RECIPE, * PRECIPE;

//C
RECIPE CreateRecipe(char* Name, INGREDIENT* IngredientList, STEP* StepList);
RECIPE CopyRecipe(RECIPE recipe);

//R
void DisplayRecipe(RECIPE RecipeHead);

char* GetRecipeName(RECIPE* recipe);

//U
bool SetRecipeName(RECIPE* recipe, char* Name);

//D
void DestroyRecipe(RECIPE* recipe);