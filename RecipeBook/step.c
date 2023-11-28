#include <string.h>
#include "step.h"

STEP CreateStep(int Num, char* Instruction) {
	STEP step;

	step.num = Num;

	step.instruction = (char*)malloc(sizeof(char) * strlen(Instruction);
	strcpy(step.instruction, Instruction);

	return step;
}

int GetStepNum(STEP step) {
	return step.num;
}

char* GetStepinstruction(STEP step) {
	return step.instruction;
}

STEP CopyStep(STEP step) {


}