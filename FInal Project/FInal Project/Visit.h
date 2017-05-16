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
	time_t Admitted() const;
	void Admitted(time_t timeIn);

	time_t Discharged() const;
	void Discharged(time_t timeOut);

	std::string Provider() const;
	void Provider(std::string providerName);

	int Severity() const;
	void Severity(int severity);

	//Public methods
	double Duration();

};

inline bool operator==(const Visit& lhs, const Visit& rhs);
inline bool operator!=(const Visit& lhs, const Visit& rhs);
inline bool operator< (const Visit&, const Visit& rhs);
inline bool operator> (const Visit& lhs, const Visit& rhs);
inline bool operator<=(const Visit& lhs, const Visit& rhs);
inline bool operator>=(const Visit& lhs, const Visit& rhs);

#endif // !_VISIT_C
