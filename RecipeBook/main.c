
#include <stdio.h>
#include "listnode.h"
#include "data.h"

void main(void) {

	PLISTNODE RecipeHead = NULL;

	PushRecipeToList(RecipeHead, CreateDataFromRecipe(CreateRecipe(5, "Cinamon Buns")));
	PushIngredientToList(RecipeHead, CreateDataFromRecipe(CreateRecipe(1, "Cinamon Buns")), CreateDataFromIngredient(CreateIngredient(1, "Cinamon")));


	PLISTNODE current = RecipeHead;
	while (current != NULL) {
		PLISTNODE currentIngredient = current->data.recipe.ingredientHead;
		printf("The recipe name is: %s\n", current->data.recipe.name);

		printf("Ingredients:\n");
		while (currentIngredient != NULL) {
			printf("$s \n", currentIngredient->data.ingredient.name);
		}
		
	}


	DestroyIngredientList(RecipeHead);
	DestroyRecipeList(RecipeHead);

}