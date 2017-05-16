#ifndef _PATIENT_C
#define _PATIENT_C

#include "Visit.h"

#include <ctime>
#include <string>
#include <vector>

class Patient {
private:
	std::string name;
	Visit* _visit;
	int severity;
public:
	//Constructors
	Patient(std::string patientName);

	//Getters and Setters
	std::string Name();
	void Name(std::string newName);

	int getSeverety();

	Visit* visit();
	//TODO: determine whether visits should be directly writable
	//void Visits(std::vector<Visit>);

	//Public methods
	void AddVisit(int timeIn, int visit);


};

#endif // !_PATIENT_C