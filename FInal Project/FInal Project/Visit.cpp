#include "Visit.h"

//GettersAndSetters
time_t Visit::Admitted() const {
	return admitted;
}
void Visit::Admitted(time_t timeIn)
{
	admitted = timeIn;
}

time_t Visit::Discharged() const {
	return discharged;
}

void Visit::Discharged(time_t timeOut) {
	discharged = timeOut;
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

inline bool operator==(const Visit& lhs, const Visit& rhs) { 
	return lhs.Severity() == rhs.Severity();
}
inline bool operator!=(const Visit& lhs, const Visit& rhs) { return !operator==(lhs, rhs); }
inline bool operator< (const Visit& lhs, const Visit& rhs) { 
	return lhs.Severity < rhs.Severity;
}
inline bool operator> (const Visit& lhs, const Visit& rhs) { return  operator< (rhs, lhs); }
inline bool operator<=(const Visit& lhs, const Visit& rhs) { return !operator> (lhs, rhs); }
inline bool operator>=(const Visit& lhs, const Visit& rhs) { return !operator< (lhs, rhs); }