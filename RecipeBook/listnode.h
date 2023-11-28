#pragma once

#include "data.h"

typedef struct listnode {
	DATA data;
	struct listnode* next;
}LISTNODE, *PLISTNODE;


bool PushRecipeToList(PLISTNODE* ListHead, DATA data);


bool PushIngredientToList(PLISTNODE* ListHead, char* RecipeName, DATA data);

bool PushStepToList(PLISTNODE* ListHead, char* RecipeName, DATA data);