#pragma once
#include "Patient.h"
class Medic
{
public:
	Medic();
	~Medic();


	virtual void takePatient(Patient& patient); // will allow the doctor to work with the patient directly
	virtual int calculateWorkTime(int time);
private:

};

