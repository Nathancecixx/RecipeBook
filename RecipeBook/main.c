#include <stdio.h>
#include <stdbool.h>
#include "utility.h"
#include "menu.h"
#include "listnode.h"

int main() {

    //-----------------------------------------------
    //              Initialize Program
    //-----------------------------------------------

    PLISTNODE ListHead = NULL;



    //-----------------------------------------------
    //              Update Program
    //-----------------------------------------------

    int flag = 1;
    while (flag) {
        PrintMenu();
        char input = TakeInput();

        switch (input) {

        case 'a':
            if (!AddNewRecipeToList(&ListHead))
                printf("Failed to add new recipe.\n");
            else
                printf("Seccusfully added new recipe.\n");
            break;

        case 'b':
            if (!DeleteRecipeFromList(&ListHead))
                printf("Failed to delete recipe.\n");
            else
                printf("Seccusfully deleted recipe.\n");
            break;

        case 'c':
            printf("c selected\n");
            break;

        case 'd':
            if (!DisplayOptions(&ListHead))
                printf("Failed to display.\n");
            break;

        case 'e':
            printf("e selected\n");
            break;

        case 'f':
            flag = 0;
            break;

        default:
            fprintf(stderr, "Input Error: invalid input\n");
            break;
        }
    }


    //-----------------------------------------------
    //             De-Initialize Program
    //-----------------------------------------------

    DestroyList(&ListHead);

    return 0;
}
