#pragma once
#include <string>

class Medic
{
public:
	Medic();
	~Medic();

	virtual int calculateWorkTime(int time) = 0;
	virtual std::string getName();

	virtual int getRemainingTime();
	virtual void setRemainingTime(int time);

	virtual void decrementTime();

private:

	static int UUID;
	int remainingTime;
	std::string name;

};

