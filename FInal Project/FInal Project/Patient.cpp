#include "Patient.h"
#include <string>

Patient::Patient(std::string patientName)
{
	this->name = patientName;
	int number = rand() % 100 + 1; // will return a number between 1 and 100
	
	// sets severity level automatically
	if (number <= 70)
		severity = rand() % 10 + 1; // will return a severity between 1 and 10 70% of the time
	if (number > 70 && number <= 90)
		severity = rand() % 5 + 11; // will return a severity between 11 and 15 20% of the time
	if (number > 90 && number <= 100)
		severity = rand() % 5 + 16; // will return a severity between 16 and 20 10% of the time
}

std::string Patient::Name() {
	return this->name;
}

void Patient::Name(std::string newName) {
	this->name = newName;
}

int Patient::getSeverety()
{
	return severity;
}

Visit* Patient::visit() {
	return _visit;
}

<<<<<<< HEAD
void Patient::AddVisit(time_t timeIn, int severity) {
	Visit* visit = new Visit(timeIn, severity);
	visits.push_back(visit);
=======
void Patient::AddVisit(time_t timeIn, time_t timeOut, std::string providerName) {
	Visit* visit = new Visit(timeIn, timeOut, providerName, severity);
	_visit = visit;
>>>>>>> 124b237acda754943097176ead8c87d5976c5d69
}

