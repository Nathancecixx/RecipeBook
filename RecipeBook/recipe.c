
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "recipe.h"


//C
RECIPE CreateRecipe(char* Name, INGREDIENT* IngredientList, STEP* StepList) {
    RECIPE recipe;

    strncpy(recipe.name, Name, MAX_RECIPE_NAME);
    recipe.ingredientList = IngredientList;
    recipe.stepList = StepList;

    return recipe;
}

RECIPE CopyRecipe(RECIPE Recipe) {
    RECIPE newRecipe;

    strncpy(newRecipe.name, Recipe.name, MAX_RECIPE_NAME);
    newRecipe.stepList = Recipe.stepList;
    newRecipe.ingredientList = Recipe.ingredientList;

    return newRecipe;
}


//R
void DisplayRecipe(RECIPE Recipe) {
    printf("Name: %s\n", Recipe.name);
    printf("Ingredients: \n");
    DisplayIngredients();
    printf("Steps: \n");
    DisplaySteps();
}

char* GetRecipeName(RECIPE* recipe) {
    return recipe->name;
}

//U
bool SetRecipeName(RECIPE* recipe, char* Name) {
    if (recipe == NULL)
        return false;

    strncpy(recipe->name, Name, MAX_RECIPE_NAME);
    return true;
}

//D
void DestroyRecipe(RECIPE* recipe) {
    DestroyIngredient(recipe->ingredientList);
    DestroySteps(recipe->stepList);

}
