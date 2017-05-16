#include "Visit.h"

//Constructors
Visit::Visit(int timeIn) :
	admitted(timeIn)
{
	int number = rand() % 100 + 1; // will return a number between 1 and 100

	// sets severity level automatically
	if (number <= 70)
		severity = rand() % 10 + 1; // will return a severity between 1 and 10 70% of the time
	if (number > 70 && number <= 90)
		severity = rand() % 5 + 11; // will return a severity between 11 and 15 20% of the time
	if (number > 90 && number <= 100)
		severity = rand() % 5 + 16; // will return a severity between 16 and 20 10% of the time
}

Visit::Visit(int timeIn, std::string providerName) :
	admitted(timeIn),
	providerName(providerName)
{
	int number = rand() % 100 + 1; // will return a number between 1 and 100

	// sets severity level automatically
	if (number <= 70)
		severity = rand() % 10 + 1; // will return a severity between 1 and 10 70% of the time
	if (number > 70 && number <= 90)
		severity = rand() % 5 + 11; // will return a severity between 11 and 15 20% of the time
	if (number > 90 && number <= 100)
		severity = rand() % 5 + 16; // will return a severity between 16 and 20 10% of the time
}

Visit::Visit(int timeIn, int timeOut, std::string providerName) :
	admitted(timeIn),
	discharged(timeOut),
	providerName(providerName)
{
	int number = rand() % 100 + 1; // will return a number between 1 and 100

	// sets severity level automatically
	if (number <= 70)
		severity = rand() % 10 + 1; // will return a severity between 1 and 10 70% of the time
	if (number > 70 && number <= 90)
		severity = rand() % 5 + 11; // will return a severity between 11 and 15 20% of the time
	if (number > 90 && number <= 100)
		severity = rand() % 5 + 16; // will return a severity between 16 and 20 10% of the time
}

Visit::~Visit() {

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

std::string Visit::Name()
{
	return patientName;
}

void Visit::Name(std::string name)
{
	this->patientName = name;
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
	return lhs.Severity() < rhs.Severity();
}
inline bool operator> (const Visit& lhs, const Visit& rhs) { return  operator< (rhs, lhs); }
inline bool operator<=(const Visit& lhs, const Visit& rhs) { return !operator> (lhs, rhs); }
inline bool operator>=(const Visit& lhs, const Visit& rhs) { return !operator< (lhs, rhs); }