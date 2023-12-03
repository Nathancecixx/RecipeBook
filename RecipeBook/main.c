#include <stdio.h>
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
            printf("a selected\n");
            break;

        case 'b':
            printf("b selected\n");
            break;

        case 'c':
            printf("c selected\n");
            break;

        case 'd':
            printf("d selected\n");
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

    return 0;
}