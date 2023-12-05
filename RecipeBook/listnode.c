#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listnode.h"


void DisplayList(PLISTNODE ListHead) {
    PLISTNODE current = ListHead;
    //    Checks if list is empty
    if (current == NULL)
        printf("\n\nList is empty.\n");
    //    prints out list
    while (current != NULL) {
        DisplayRecipe(current->recipe);
        current = current->next;
    }
}

void DisplayListRange(PLISTNODE ListHead, RECIPE_TYPE RecipeType) {
    PLISTNODE current = ListHead;
    //    Checks if list is empty
    if (current == NULL)
        printf("\n\nList is empty.\n");
    //    prints out list
    while (current != NULL) {
        if (GetRecipeType(current->recipe) == RecipeType)
            DisplayRecipe(current->recipe);
        current = current->next;
    }
}

void DisplayRecipeInList(PLISTNODE ListHead, char* RecipeName) {
    PLISTNODE current = ListHead;
    while (current != NULL && strcmp(current->recipe.name, RecipeName) != 0) {
        current = current->next;
    }

    if (current == NULL)
        fprintf(stderr, "Unable to find recipe in list.\n");

    DisplayRecipe(current->recipe);
}

bool AddNodeToList(PLISTNODE* ListHead, RECIPE recipe) {
    PLISTNODE NewNode = (PLISTNODE)malloc(sizeof(LISTNODE));
    if (NewNode == NULL)
        return false;

    NewNode->recipe = CopyRecipe(recipe);

    NewNode->next = *ListHead;
    *ListHead = NewNode;
    return true;
}

bool RemoveNodeFromList(PLISTNODE* ListHead, char* Name) {
    PLISTNODE current = *ListHead;

    //    Check if the first item is what we are looking for
    if (current != NULL && strcmp(current->recipe.name, Name) == 0) {
        //        Check if theres a second item to set the head to
        if (current->next != NULL) {
            *ListHead = current->next;
            //            if not then set head to NULL
        }
        else {
            *ListHead = NULL;
        }
        //        Destroy first item
        DestroyNode(current);
        return true;
    }

    //    There is a first item and its not what we want.
    //    iterate through list until we find it or end
    PLISTNODE prev = NULL;
    while (current != NULL && strcmp(current->recipe.name, Name) != 0) {
        prev = current;
        current = current->next;
    }

    //    Check if we are at the end of list
    if (current == NULL)
        return false;

    //    We must have found it therefore remove it from chain
    //    and Destroy it
    prev->next = current->next;
    DestroyNode(current);
    return true;
}

bool SearchNodeInList(PLISTNODE* ListHead, char* Name) {
    PLISTNODE current = *ListHead;

    //    There is a first item and its not what we want.
    //    iterate through list until we find it or end
    PLISTNODE prev = NULL;
    while (current != NULL && strcmp(current->recipe.name, Name) != 0) {
        prev = current;
        current = current->next;
    }

    //    Check if we are at the end of list
    if (current == NULL)
        return false;

    //    We must have found it
    return true;
}

void DestroyNode(PLISTNODE ListNode) {
    DestroyRecipe(&ListNode->recipe);
    free(ListNode);
}

void DestroyList(PLISTNODE* ListHead) {
    PLISTNODE current = *ListHead;

    //    Iterate through destroying each node in list
    while (current != NULL) {
        DestroyNode(current);
        current = current->next;
    }
}