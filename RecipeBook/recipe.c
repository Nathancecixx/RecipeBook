#include "recipe.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//C
RECIPE CreateRecipe(char* Name, RECIPE_TYPE RecipeType, int IngredientCount, INGREDIENT* IngredientList, int StepCount, STEP* StepList) {
    RECIPE recipe;

    recipe.recipeType = RecipeType;
    strncpy(recipe.name, Name, MAX_RECIPE_NAME);

    recipe.ingredientCount = IngredientCount;
    recipe.ingredientList = IngredientList;

    recipe.stepCount = StepCount;
    recipe.stepList = StepList;

    return recipe;
}

RECIPE CopyRecipe(RECIPE Recipe) {
    RECIPE newRecipe;

    newRecipe.recipeType = Recipe.recipeType;
    strncpy(newRecipe.name, Recipe.name, MAX_RECIPE_NAME);

    newRecipe.ingredientCount = Recipe.ingredientCount;
    newRecipe.ingredientList = Recipe.ingredientList;

    newRecipe.stepCount = Recipe.stepCount;
    newRecipe.stepList = Recipe.stepList;

    return newRecipe;
}


//R
void DisplayRecipe(RECIPE Recipe) {
    int spacesNeeded = 35 - (int)strlen(Recipe.name);
    printf(""
        "\n+--------------------------------------------------------+"
        "\n|         %s%*s            |"
        "\n+--------------------------------------------------------+", Recipe.name, spacesNeeded, "");

    //    printf("Name: %s\n", Recipe.name);

    printf("\n    Ingredients: \n");
    for (int i = 0; i < Recipe.ingredientCount; i++) {
        printf("        %s\n", getIngredient(Recipe.ingredientList[i]));
    }

    printf("\n    Steps: \n");
    for (int i = 0; i < Recipe.stepCount; i++) {
        DisplayStep(Recipe.stepList[i]);
    }

    //DisplaySteps();
}

char* GetRecipeName(RECIPE* recipe) {
    return recipe->name;
}

RECIPE_TYPE GetRecipeType(RECIPE recipe) {
    return recipe.recipeType;
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
    //DestroySteps(recipe->stepList);

}
