#include "Medic.h"


int Medic::UUID = -1;

Medic::Medic()
{
	UUID++; // incrememnts the static variable
	name = std::to_string(UUID); // gives a unique name to each and every doctor and nurse
	remainingTime = 0;
}


Medic::~Medic()
{
}

std::string Medic::getName()
{
	return name;
}

int Medic::getRemainingTime()
{
	return remainingTime;
}

void Medic::setRemainingTime(int time)
{
	this->remainingTime = time;
}

void Medic::decrementTime()
{
	if (remainingTime > 0)
		remainingTime--;
}

//int Medic::getCurrentOffice()
//{
//	return currentOffice;
//}
//
//void Medic::setCurrentOffice(int office)
//{
//	this->currentOffice = office;
//}
