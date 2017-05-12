#pragma once
#include "Medic.h"
class Doctor :
	public Medic
{
public:
	Doctor() : Medic() {};
	~Doctor();

	virtual int calculateWorkTime(int clock);
};

