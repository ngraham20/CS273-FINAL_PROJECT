#include "Doctor.h"

Doctor::~Doctor()
{
}

int Doctor::calculateWorkTime(int clock)
{
	return rand() & 20 + 1;
}
