#pragma once

typedef struct {
	int num;
	char* instruction;
}STEP;



STEP CreateStep(int Num, char* Name);

int GetStepNum(STEP step);

char* GetStepinstruction(STEP step)

STEP CopyStep(STEP setp);