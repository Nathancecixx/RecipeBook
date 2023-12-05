#pragma once

#include <stdbool.h>
#include "ingredient.h"
#include "step.h"

#define MAX_RECIPE_NAME       25

typedef enum { BREAKFAST, LUNCH, DINNER, SNACK }RECIPE_TYPE;


typedef struct recipe {
    char name[MAX_RECIPE_NAME];
    RECIPE_TYPE recipeType;
    int ingredientCount;
    INGREDIENT* ingredientList;
    int stepCount;
    STEP* stepList;
}RECIPE, * PRECIPE;

//C
RECIPE CreateRecipe(char* Name, RECIPE_TYPE RecipeType, int IngredientCount, INGREDIENT* IngredientList, int StepCount, STEP* StepList);
RECIPE CopyRecipe(RECIPE recipe);

//R
void DisplayRecipe(RECIPE RecipeHead);

char* GetRecipeName(RECIPE* recipe);
RECIPE_TYPE GetRecipeType(RECIPE recipe);

//U
bool SetRecipeName(RECIPE* recipe, char* Name);

//D
void DestroyRecipe(RECIPE* recipe);