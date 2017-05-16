#ifndef _VISIT_C
#define _VISIT_C

#include <ctime>
#include <string>

class Visit {
	int admitted;
	int discharged;
	std::string providerName;
	int severity;
	std::string patientName;
	

public:
	//Constructors
	Visit(int timeIn);
	Visit(int timeIn, std::string providerName);
	Visit(int timeIn, int timeOut, std::string providerName);

	//Destructor
	~Visit();

	//GettersAndSetters
	int Admitted() const;
	void Admitted(int timeIn);

	int Discharged() const;
	void Discharged(int timeOut);

	std::string Provider() const;
	void Provider(std::string providerName);

	int Severity() const;
	void Severity(int severity);

	std::string Name();
	void Name(std::string name);

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
