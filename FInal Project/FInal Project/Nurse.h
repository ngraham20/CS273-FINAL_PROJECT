#pragma once
#include "Medic.h"
class Nurse :
	public Medic
{
public:
	Nurse() : Medic() {};
	~Nurse();

	virtual int calculateWorkTime(int clock);
};

