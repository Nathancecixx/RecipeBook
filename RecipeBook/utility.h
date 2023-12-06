#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "listnode.h"
#include "recipe.h"
#include "ingredient.h"
#include "step.h"

#define CHUNK_OF_LIST   5
#define DIFF_BETWEEN_CASES    32


bool AddNewRecipeToList(PLISTNODE* ListHead);

bool DeleteRecipeFromList(PLISTNODE* ListHead);

bool UpdateRecipeInList(PLISTNODE* ListHead);

bool DisplayOptions(PLISTNODE* ListHead);

bool DisplaySingleRecipe(PLISTNODE* ListHead);

bool DisplayRecipeRange(PLISTNODE* ListHead);

bool DisplayAllRecipe(PLISTNODE* ListHead);

bool SearchForRecipeInList(PLISTNODE* ListHead);

char* takeInputAsSentance(char* Prompt);

RECIPE_TYPE takeInputAsRecipeType(char* Prompt);

char takeInputAsChar(char* Prompt);

char* takeInputAsString(char* InputType);

void clearInputBuffer();