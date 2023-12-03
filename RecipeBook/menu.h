#pragma once

#include <stdbool.h>

#define DIFFBETWEENCASES    32
#define INPUTSIZE   3

void PrintMenu();
char TakeInput();
void SetInputToLowerCase(char*);
bool checkInput(const char*);