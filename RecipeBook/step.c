#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "step.h"



STEP CreateStep(int Num, char* Sentance) {
    STEP step;

    step.num = Num;
    strcpy(step.sentance, Sentance);
    return step;
}
STEP CopyStep(STEP dest) {
    STEP step;

    step.num = dest.num;
    strcpy(step.sentance, dest.sentance);
    return step;
}

void DisplayStep(STEP step) {
    printf("        %s\n", step.sentance);
}

void DestroyStep(STEP* step) {
    free(step);
}