#pragma once
#include "Patient.h"
class Medic
{
public:
	Medic();
	~Medic();


	//virtual void takePatient(Patient& patient); // will allow the doctor to work with the patient directly
	virtual int calculateWorkTime(int time) = 0;
	virtual std::string getName();

	virtual int getRemainingTime();
	virtual void setRemainingTime(int time);

	virtual void decrementTime();

//	int getCurrentOffice();
//	void setCurrentOffice(int office);
private:

	static int UUID;
//	int currentOffice;
	int remainingTime;
	std::string name;

};

