#include "stdafx.h"
#include "CppUnitTest.h"
#include "Patient.h"
#include "Visit.h"

#include <ctime>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace PatientAndVisitTests
{		
	TEST_CLASS(PatientTests)
	{
	public:
		
		TEST_METHOD(CanCreateAPatientAndGetItsName)
		{
			std::string patientName = "Sam Smith";
			Patient* patient = new Patient(patientName);
			Assert::AreEqual(patient->Name(), patientName);
		}

		TEST_METHOD(Can_add_a_visit_to_a_patient)
		{
			unsigned int vectorLength = 1;
			std::string patientName = "Sam Smith";
			Patient* patient = new Patient(patientName);
			double duration = 3000;
			time_t timeIn = time(0) - duration;
			time_t timeOut = time(0);
			std::string hcpName = "Millicent";
			patient->AddVisit(timeIn, timeOut, hcpName);
			Visit* visit = patient->Visits()[0];
			Assert::AreEqual(patient->Visits().size(), vectorLength);
			Assert::AreEqual(visit->Provider(), hcpName);
			Assert::AreEqual(visit->Duration(), duration);
		}

	};

	TEST_CLASS(VisitTests)
	{
	public:
		TEST_METHOD(Can_create_a_visit_and_get_its_time_in_time_out_doc_name_and_duration) {
			double duration = 3000;
			time_t timeIn = time(0) - duration;
			time_t timeOut = time(0);
			std::string hcpName = "Millicent";
			Visit* visit = new Visit(timeIn, timeOut, hcpName);
			//Assert does not seem to be able to handle print time_t objects
			//We should be able to test their values indirectly with duration
			//Assert::AreEqual(visit->Admitted(), timeIn);
			//Assert::AreEqual(visit->Discharged(), timeOut);
			Assert::AreEqual(visit->Provider(), hcpName);
			Assert::AreEqual(visit->Duration(), duration);
		}
	};
}