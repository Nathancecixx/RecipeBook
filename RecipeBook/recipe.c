
#include "recipe.h"



RECIPE CreateRecipe(int NumberOfSteps, char* Name) {
    RECIPE recipe;

    recipe.numberOfSteps = NumberOfSteps;
    strncpy(recipe.name, Name, 25);
    recipe.ingredientHead = NULL;
    recipe.stepHead = NULL;

    return recipe;
}

bool AddIngredientToRecipe(RECIPE* recipe, int Num, char* Name) {
    PLISTNODE current = recipe->ingredientHead;
    while (current != NULL) {
        current = current->next;
    }

    current->data = CreateDataFromIngredient(CreateIngredient(Num, Name));

}

RECIPE CopyRecipe(RECIPE recipe) {
    RECIPE r;
    r.ingredientHead = recipe.ingredientHead;
    r.stepHead = recipe.stepHead;
    r.numberOfSteps = recipe.numberOfSteps;
    strncpy(r.name, recipe.name, 25);

    return r;
}