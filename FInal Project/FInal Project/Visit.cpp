#include "Visit.h"

//GettersAndSetters
time_t Visit::Admitted() {
	return admitted;
}
void Visit::Admitted(time_t timeIn)
{
	admitted = timeIn;
}

time_t Visit::Discharged() {
	return discharged;
}

void Visit::Discharged(time_t timeOut) {
	discharged = timeOut;
}

std::string Visit::Provider() {
	return providerName;
}

void Visit::Provider(std::string providerName) {
	this->providerName = providerName;
}

//Public methods
double Visit::Duration() {
	return difftime(discharged, admitted);
}
