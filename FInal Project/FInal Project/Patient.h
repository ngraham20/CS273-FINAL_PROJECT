#ifndef _PATIENT_C
#define _PATIENT_C

#include "Visit.h"

#include <ctime>
#include <string>
#include <vector>

class Patient {
private:
	std::string name;
	std::vector<Visit*> visits;
	int severity;
public:
	//Constructors
	Patient(std::string patientName);

	//Getters and Setters
	std::string Name();
	void Name(std::string newName);

	int getSeverety();

	std::vector<Visit*> Visits();
	//TODO: determine whether visits should be directly writable
	//void Visits(std::vector<Visit>);

	//Public methods
	void AddVisit(time_t timeIn, int visit);

	Visit* getLastVisit();
};

#endif // !_PATIENT_C