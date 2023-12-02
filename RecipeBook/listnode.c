
#include <stdlib.h>
#include "listnode.h"

bool PushRecipeToList(PLISTNODE* ListHead, DATA data) {
	PLISTNODE current = ListHead;

	PLISTNODE NewNode = (PLISTNODE) malloc(sizeof(NewNode));
	if (NewNode == NULL)
		return false;

	NewNode->data = CopyData(data);
	NewNode->next = current->next;

	ListHead = NewNode;

	return true;
}

bool PushIngredientToList(PLISTNODE* ListHead, DATA recipe, DATA data) {
	PLISTNODE current = ListHead;
	if (current == NULL)
		return false;


	PLISTNODE NewNode = (PLISTNODE)malloc(sizeof(NewNode));
	if (NewNode == NULL)
		return false;

	while (current != NULL) {
		if (CompareRecipe(current->data.recipe, recipe.recipe)) {
			NewNode->next = current->next;
			current->data.recipe.ingredientHead = NewNode;
			break;
		}
	}

	return true;
}

bool PushStepToList(PLISTNODE* ListHead, char* RecipeName, DATA data) {

}

void DestroyRecipeList(PLISTNODE* ListHead) {
	PLISTNODE current = *ListHead;
	while (current != NULL) {
		PLISTNODE tmp = current;
		current = current->next;
		//Destroy Data
		free(tmp);
	}
	ListHead = NULL;

}

void DestroyIngredientList(PLISTNODE* ListHead) {

}