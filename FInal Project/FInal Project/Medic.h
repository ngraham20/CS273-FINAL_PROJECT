#pragma once
#include <string>

class Medic
{
public:
	Medic();
	~Medic();

	virtual int calculateWorkTime(int time) = 0;
	std::string getName();

	int getRemainingTime();
	void setRemainingTime(int time);

	void decrementTime();

private:

	static int UUID;
	int remainingTime;
	std::string name;

};

