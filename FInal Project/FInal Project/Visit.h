#ifndef _VISIT_C
#define _VISIT_C

#include <ctime>
#include <string>

class Visit {
	time_t admitted;
	time_t discharged;
	std::string providerName;
	int severity;

public:
	//Constructors
	Visit(time_t timeIn, int severity) :
		admitted(timeIn),
		severity(severity)
	{}

	//GettersAndSetters
	time_t Admitted();
	void Admitted(time_t timeIn);

	time_t Discharged();
	void Discharged(time_t timeOut);

	std::string Provider();
	void Provider(std::string providerName);

	int Severity();
	void Severity(int severity);

	//Public methods
	double Duration();

};

#endif // !_VISIT_C
