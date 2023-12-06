#include "step.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



STEP CreateStep(int Num, char* Sentance) {
    STEP step;

    step.num = Num;
    step.sentance = Sentance;
    return step;
}
STEP CopyStep(STEP dest) {
    STEP step;

    step.num = dest.num;
    strcpy(step.sentance, dest.sentance);
    return step;
}

void DisplayStep(STEP step) {
    printf("        %d) %s\n", step.num, step.sentance);
}

void DestroyStep(STEP* step) {
    free(step->sentance);
    free(step);
}