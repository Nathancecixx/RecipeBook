#pragma once

#include "data.h"

typedef struct listnode {
	DATA data;
	struct listnode* next;
}LISTNODE, *PLISTNODE;


bool PushRecipeToList(PLISTNODE* ListHead, DATA data);

bool PushIngredientToList(PLISTNODE* ListHead, DATA recipe, DATA data);

bool PushStepToList(PLISTNODE* ListHead, char* RecipeName, DATA data);

void DestroyRecipeList(PLISTNODE* ListHead);

void DestroyIngredientList(PLISTNODE* ListHead);