#pragma once

#include "recipe.h"

typedef struct listnode {
    RECIPE recipe;
    struct listnode* next;
}LISTNODE, * PLISTNODE;

void DisplayList(PLISTNODE ListHead);
void DisplayListRange(PLISTNODE ListHead, RECIPE_TYPE RecipeType);

void DisplayRecipeInList(PLISTNODE ListHead, char* RecipeName);

bool AddNodeToList(PLISTNODE* ListHead, RECIPE recipe);

bool RemoveNodeFromList(PLISTNODE* ListHead, char* Name);

bool SearchNodeInList(PLISTNODE* ListHead, char* Name);

void DestroyNode(PLISTNODE ListNode);

void DestroyList(PLISTNODE* ListHead);