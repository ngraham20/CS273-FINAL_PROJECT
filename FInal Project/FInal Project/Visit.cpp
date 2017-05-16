#include "Visit.h"

Visit::Visit(int timeIn, int severity)
{
	this->admitted = timeIn;
	this->severity = severity;
}

//GettersAndSetters
int Visit::Admitted() const {
	return admitted;
}
void Visit::Admitted(int timeIn)
{
	admitted = timeIn;
}

int Visit::Discharged() const {
	return discharged;
}

void Visit::Discharged(int timeOut) {
	this->discharged = timeOut;
}

std::string Visit::Provider() const {
	return providerName;
}

void Visit::Provider(std::string providerName) {
	this->providerName = providerName;
}

int Visit::Severity() const {
	return severity;
}

void Visit::Severity(int severity) {
	this->severity = severity;
}

//Public methods
double Visit::Duration() {
	return difftime(discharged, admitted);
}
//
//inline bool operator==(const Visit& lhs, const Visit& rhs) { 
//	return lhs.Severity() == rhs.Severity();
//}
//inline bool operator!=(const Visit& lhs, const Visit& rhs) { return !operator==(lhs, rhs); }
//inline bool operator< (const Visit& lhs, const Visit& rhs) { 
//	return lhs.Severity < rhs.Severity;
//}
//inline bool operator> (const Visit& lhs, const Visit& rhs) { return  operator< (rhs, lhs); }
//inline bool operator<=(const Visit& lhs, const Visit& rhs) { return !operator> (lhs, rhs); }
//inline bool operator>=(const Visit& lhs, const Visit& rhs) { return !operator< (lhs, rhs); }