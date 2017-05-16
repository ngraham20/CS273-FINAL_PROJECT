#include "Nurse.h"

Nurse::~Nurse()
{
}

int Nurse::calculateWorkTime(int clock)
{
	return rand() % 10 + 1;
}

