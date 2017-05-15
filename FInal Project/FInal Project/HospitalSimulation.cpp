#include "HospitalSimulation.h"



//HospitalSimulation::HospitalSimulation()
//{
//	numServed = 0;
//
//	// initialize random seed
//	srand(time(NULL));
//}


HospitalSimulation::~HospitalSimulation()
{
}

HospitalSimulation::HospitalSimulation(int arrivalRate, int totalDoctors, int totalNurses)
{
	numServed = 0;
	totalWaitTime = 0;

	patientArrivalRate = arrivalRate;

	// initialize random seed
	srand(time(NULL));

	// generates vectors with pre-determined 
	// sizes and default values
	for (int i = 0; i < totalDoctors; i++)
	{
		this->doctors.push_back(new Doctor());
	}
	for (int i = 0; i < totalNurses; i++)
	{
		this->nurses.push_back(new Nurse());
	}

	// generates empty "offices" to put patients in
	this->offices = std::vector<Patient*>(totalDoctors + totalNurses, NULL);

}

void HospitalSimulation::runSimulation(int maxTime)
{
	// reads all patients from the file into a vector
	std::vector<std::string> patients = readPatients();

	for (int time = 0; time < maxTime; time++)
	{
		// update waiting room, doctors, nurses, and registrar
		updateWaitingRoom(patients, time); // pulls patients into the waiting room
		updateNurses(time); // updates nurses to do their jobs (before doctors, to be patient-efficient)
		updateDoctors(time); // updates doctors to do their jobs
	}
	std::cout << "\n Total number of patients served: " << numServed << std::endl;
	std::cout << "Total wait time: " << totalWaitTime << std::endl;
	return;
}

int HospitalSimulation::getAverage()
{
	return totalWaitTime/numServed;
}

void HospitalSimulation::printRecordsByPatient(std::string name)
{
	// TODO, Christian, this is yours too
}

void HospitalSimulation::printAllPatientNames()
{
	// TODO Christian, go ahead and do with this what you wil for the UI
}

std::vector<std::string> HospitalSimulation::readPatients()
{
	// TODO change names.txt to use the official text file
	std::string fileName = ".\\names.txt";
	std::ifstream input;
	std::vector<std::string> vec;
	std::string word;

	input.open(fileName.c_str());

	if (!input.fail())
	{
		while (!input.eof())
		{
			input >> word;
			if (word != "/n")
			{
				vec.push_back(word);
			}
		}
		input.close();
	}
	else
	{
		std::cout << "Could not open file. . ./n";
	}
	return vec;
}

// this will alwasy pull a patient and push him/her into the heap
Patient * HospitalSimulation::patientArrival(std::vector<std::string>& patients, int index)
{
	Patient* patient = new Patient(patients.at(index)); // creates a new patient based on the selected name

	waitingRoom.push(patient); // adds the patient to the waiting room

	return patient;
}

void HospitalSimulation::updateWaitingRoom(std::vector<std::string>& patients, int clock)
{
	int count = 0;
	for (int i = 0; i < 60; i++) // loops 60 times for every tick of simulation time (60s/min)
	{
		// patients have an hourly patientArrivalRate / 3600 of arriving in a given second
		int patientArrival = rand() % (3600); 
		if (patientArrival <= patientArrivalRate) 
		{
			count++; // increase the counter
		}
	}
	for (int i = 0; i < count; i++) // will pull as many patients as arrived (calculated above)
	{
		patientArrival(patients, rand() % patients.size()); // pulls the patients from the vector and inserts him into the heap
	}
}

void HospitalSimulation::updateDoctors(int clock)
{
	for (int i = 0; i < doctors.size(); i++) // loop through all doctors
	{
		Doctor* doc = doctors.at(i);

		if (doc->getRemainingTime() == 0) // the doctor will see you now
		{
			// first deal with the patient he's currently working with (if he is)
			if (offices[i] != NULL) // has a patient
			{
				// first, add all patient's visits to registrar under the same name
				Patient* patient = offices[i];
				registrar[patient->Name()].push_back(patient->visit());

				totalWaitTime += patient->visit()->Discharged() - patient->visit()->Admitted();
				numServed++;

				offices[i] = NULL; // removes the patient from the offices
			}

			// then do whatever he wants
			// grab a patient (if available) from the heap
			if (waitingRoom.size() > 0)
			{
				Patient* patient = waitingRoom.pop();

				// calculate work time
				int visitTime = doc->calculateWorkTime(clock);

				// set doc's remaining time to work time
				doc->setRemainingTime(visitTime);

				// create a visitation log for the patient
				//                  c_T      end time        name of doc
				patient->AddVisit(clock, clock + visitTime, doc->getName());

				// send the patient to the doctor's office
				offices.at(i) = patient;
			}
		}
		else // the doctor is busy at the moment
		{
			doctors.at(i)->decrementTime(); // decrement the doctor's remainint time
		}
	}
}

void HospitalSimulation::updateNurses(int clock)
{
	for (int i = 0; i < nurses.size(); i++) // loop through all nurses
	{
		Nurse* nurse = nurses.at(i);

		if (nurse->getRemainingTime() == 0) // the nurse will see you now
		{
			// first deal with the patient he's currently working with (if he is)
			if (offices[i+doctors.size()] != NULL) // has a patient in a nurse's office
			{
				// first, add all patient's visits to registrar under the same name
				Patient* patient = offices[i+doctors.size()];
				registrar[patient->Name()].push_back(patient->visit());
				offices[i+doctors.size()] = NULL; // removes the patient from the offices
				numServed++;
			}

			// grab a patient (if available) from the heap
			if (waitingRoom.size() > 0)
			{
				Patient* patient = waitingRoom.front();

				if (patient->getSeverety() <= 10) // if the nurse can deal with this patient
				{
					waitingRoom.pop(); // pop the patient from the waiting room, then begin doing the same thing the doc would do

					// calculate work time
					int visitTime = nurse->calculateWorkTime(clock);

					// set doc's remaining time to work time
					nurse->setRemainingTime(visitTime);

					// create a visitation log for the patient
					//                  c_T      end time        name of doc
					patient->AddVisit(clock, clock + visitTime, nurse->getName());

					// send the patient to the nurse's office
					offices.at(i+doctors.size()) = patient; // will insure that nurses don't override doctor visits
				}
			}
		}
		else // the nurse is busy at the moment
		{
			nurses.at(i)->decrementTime(); // decrement the nurse's remainint time
		}
	}
}

void HospitalSimulation::updateOffices(int clock)
{
	
}

void HospitalSimulation::addDoctor()
{
}

void HospitalSimulation::addNurse()
{
}

void HospitalSimulation::updateRegistrar(std::string patientName, Visit* visit) 
{
	registrar[patientName].push_back(visit);
}
