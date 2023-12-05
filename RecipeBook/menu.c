#include <stdio.h>
#include <string.h>
#include "menu.h"

void PrintMenu() {
    printf("\n"
        "+--------------------------------------------------------+\n"
        "|  +-----------------+                         BETA: 1.0 |\n"
        "|  | Recipe Book CLI |                                   |\n"
        "|  +-----------------+                                   |\n"
        "|                                                        |\n"
        "| To choose a function, enter its letter label:          |\n"
        "|                                                        |\n"
        "| a) Add a new recipe                                    |\n"
        "| b) Delete an existing recipe                           |\n"
        "| c) Update an existing recipe                           |\n"
        "| d) Display recipes                                     |\n"
        "| e) search for recipe                                   |\n"
        "| f) Quit                                                |\n"
        "+--------------------------------------------------------+\n");
}

char TakeInput() {

    char buffer[INPUTSIZE];
    if (fgets(buffer, INPUTSIZE, stdin) == NULL) {
        fprintf(stderr, "INPUT ERROR: Failed to read menu input with fgets\n");
        return '\0';
    }

    SetInputToLowerCase(&buffer[0]);

    if (checkInput(&buffer[0])) {
        return buffer[0];
    }
    else {
        return '\0';
    }

}

bool checkInput(const char* arr) {

    if (strcspn(arr, "\n") == strlen(arr)) {
        while (getchar() != '\n');
        return false;
    }

    if ((arr[0] >= 'a' && arr[0] <= 'g')) {
        return true;
    }

    return false;
}

void SetInputToLowerCase(char* inp) {

    if (inp[0] >= 'A' && inp[0] <= 'Z') {
        inp[0] += DIFFBETWEENCASES;
    }
}