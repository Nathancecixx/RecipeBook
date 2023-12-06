#pragma once
#define _CRT_SECURE_NO_WARNINGS
typedef struct step {
    int num;
    char* sentance;
}STEP;


STEP CreateStep(int Num, char* Sentance);
STEP CopyStep(STEP Step);

void DisplayStep(STEP step);

void DestroyStep(STEP* step);