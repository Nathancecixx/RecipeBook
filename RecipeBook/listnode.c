#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listnode.h"


void DisplayList(PLISTNODE ListHead) {
    PLISTNODE current = ListHead;

    printf("Recipes: \n");

    while (current != NULL) {
        DisplayRecipe(current->recipe);
        current = current->next;
    }
}

void AddRecipeToList(PLISTNODE* ListHead, RECIPE recipe) {
    PLISTNODE NewNode = (PLISTNODE)malloc(sizeof(LISTNODE));

    NewNode->recipe = CopyRecipe(recipe);

    NewNode->next = *ListHead;
    *ListHead = NewNode;
}

bool RemoveRecipeFromList(PLISTNODE* ListHead, char* Name) {
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