#pragma once

#include "recipe.h"

typedef struct listnode {
    RECIPE recipe;
    struct listnode* next;
}LISTNODE, * PLISTNODE;

void DisplayList(PLISTNODE ListHead);

void AddRecipeToList(PLISTNODE* ListHead, RECIPE recipe);

bool RemoveRecipeFromList(PLISTNODE* ListHead, char* Name);

void DestroyNode(PLISTNODE ListNode);

void DestroyList(PLISTNODE* ListHead);