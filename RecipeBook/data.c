
#include "data.h"
#include "ingredient.h"
#include "step.h"


DATA CreateDataFromRecipe(RECIPE Recipe) {
    DATA data;
    data.dataType = RECIPE_TYPE;
    data.recipe = Recipe;

    return data;
}

DATA CreateDataFromIngredient(INGREDIENT ingredient) {
    DATA data;
    data.dataType = INGREDIENT_TYPE;
    data.ingredient = CopyIngredient(ingredient);

    return data;
}

DATA CreateDataFromStep(STEP step) {
    DATA data;
    data.dataType = STEP_TYPE;
    data.step = CopyStep(step);

    return data;
}

DATA CopyData(DATA data) {
    if (data.dataType == RECIPE_TYPE)
        return CreateDataFromRecipe(CopyRecipe(data.recipe));
    if (data.dataType == INGREDIENT_TYPE)
        return CreateDataFromIngredient(CopyIngredient(data.ingredient));
    if (data.dataType == STEP_TYPE)
        return CreateDataFromStep(CopyStep(data.step));

}