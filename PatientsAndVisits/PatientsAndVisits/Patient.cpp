#include "Patient.h"
#include <string>

std::string Patient::Name() {
	return this->name;
}

void Patient::Name(std::string newName) {
	this->name = newName;
}

std::vector<Visit*> Patient::Visits() {
	return visits;
}

void Patient::AddVisit(time_t timeIn, time_t timeOut, std::string providerName) {
	Visit* visit = new Visit(timeIn, timeOut, providerName);
	visits.push_back(visit);
}