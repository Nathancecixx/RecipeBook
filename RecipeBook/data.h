#pragma once

#include "ingredient.h"
#include "step.h"
#include "recipe.h"

typedef enum { RECIPE_TYPE, INGREDIENT_TYPE, STEP_TYPE }DATA_TYPE;

typedef union {
	DATA_TYPE dataType;
	RECIPE recipe;
	INGREDIENT ingredient;
	STEP step;
}DATA;


DATA CreateDataFromRecipe(RECIPE Recipe);
DATA CreateDataFromIngredient(INGREDIENT ingredient);

DATA CopyData(DATA data);