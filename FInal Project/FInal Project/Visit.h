#ifndef _VISIT_C
#define _VISIT_C

#include <ctime>
#include <string>

class Visit {
	int admitted;
	int discharged;
	std::string providerName;
	int severity;

public:
	//Constructors
	Visit(int timeIn, int severity);

	//GettersAndSetters
	int Admitted() const;
	void Admitted(int timeIn);

	int Discharged() const;
	void Discharged(int timeOut);

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
