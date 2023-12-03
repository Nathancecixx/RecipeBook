#pragma once

#include "listnode.h"
#include "recipe.h"
#include "ingredient.h"
#include "step.h"

//This is the interface for the functions needed to interact with data



bool AddNewRecipeToList(PLISTNODE* ListHead);

bool DeleteRecipeFromList(PLISTNODE* ListHead);

bool UpdateRecipeInList(PLISTNODE* ListHead);

bool DisplayRecipeInList(PLISTNODE* ListHead);

bool DisplayRecipeRangeInList(PLISTNODE* ListHead);

bool DisplayAllRecipeInList(PLISTNODE* ListHead);

bool SearchForRecipeInList(PLISTNODE* ListHead);
