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
	clock = 0;

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
	// this->offices = std::vector<Patient*>(totalDoctors + totalNurses, NULL);

}

void HospitalSimulation::runSimulation(int maxTime)
{
	// reads all patients from the file into a vector
	std::vector<std::string> patients = readPatients();

	for (int time = 0; time < maxTime; time++)
	{
		clock = time; // updates a global variable to use for visits n stuff
		// update waiting room, doctors, nurses, and registrar

		updateWaitingRoom(patients, time); // pulls patients into the waiting room
		updateNurses(time); // updates nurses to do their jobs (before doctors, to be patient-efficient)
//		updateDoctors(time); // updates doctors to do their jobs
	}
	std::cout << "\n Total number of patients served: " << numServed << std::endl;
	std::cout << "Total wait time: " << totalWaitTime << std::endl;
	return;
}

int HospitalSimulation::getAverage()
{
	std::cout << totalWaitTime << std::endl;
	std::cout << numServed << std::endl;
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
void HospitalSimulation::patientArrival(std::vector<std::string>& patients, int index)
{
	Patient* patient = new Patient(patients.at(index)); // creates a new patient based on the selected name

	if (patient->getSeverety() <= 10)
		waitingRoomYellow.push(patient); // adds the patient to the waiting room accessable by nurses
	else
		waitingRoomRed.push(patient); // adds the patient to the waiting room only accessable by doctors

	// add visit (without discharge time or provider name)
	patient->AddVisit(clock, patient->getSeverety());

	return;
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
	for (int i = 0; i < doctors.size(); i++)
	{
		Doctor* doc = doctors[i];
		if (doc != NULL)
		{
			if (doc->getRemainingTime() > 0)
			{
<<<<<<< HEAD
				doc->decrementTime();
			}
			else if (doc->getRemainingTime() == 0)
			{
				// the nurse is available

				if (waitingRoomRed.size() > 0) // if there are patients
				{
					Patient* patient = waitingRoomRed.pop(); // nurse takes the patient
=======
				// first, add all patient's visits to registrar under the same name
				Patient* patient = offices[i];
				registrar[patient->Name()].push_back(patient->visit());

				totalWaitTime += patient->visit()->Discharged() - patient->visit()->Admitted();
				numServed++;
>>>>>>> 124b237acda754943097176ead8c87d5976c5d69

					int workTime = doc->calculateWorkTime(clock); // calculates work time

					// nurse->setRemainingTime(workTime); // resets the nurse's time

					patient->getLastVisit()->Discharged(clock + workTime); // updates the visit

					updateRegistrar(patient->Name(), patient->getLastVisit()); // adds the visit

					totalWaitTime += patient->getLastVisit()->Discharged() - patient->getLastVisit()->Admitted();

					numServed++;

					delete patient;
				}
			}
		}
	}
}

void HospitalSimulation::updateNurses(int clock)
{
	for (int i = 0; i < nurses.size(); i++)
	{
		Nurse* nurse = nurses[i];
		if (nurse != NULL)
		{
			if (nurse->getRemainingTime() > 0)
			{
<<<<<<< HEAD
				nurse->decrementTime();
=======
				// first, add all patient's visits to registrar under the same name
				Patient* patient = offices[i+doctors.size()];
				registrar[patient->Name()].push_back(patient->visit());
				offices[i+doctors.size()] = NULL; // removes the patient from the offices
				numServed++;
>>>>>>> 124b237acda754943097176ead8c87d5976c5d69
			}
			else if (nurse->getRemainingTime() == 0)
			{
				// the nurse is available

				if (waitingRoomYellow.size() > 0) // if there are patients
				{
					Patient* patient = waitingRoomYellow.pop(); // nurse takes the patient

					int workTime = nurse->calculateWorkTime(clock); // calculates work time

					// nurse->setRemainingTime(workTime); // resets the nurse's time

					patient->getLastVisit()->Discharged(clock + workTime); // updates the visit

					updateRegistrar(patient->Name(), patient->getLastVisit()); // adds the visit

					totalWaitTime += patient->getLastVisit()->Discharged() - patient->getLastVisit()->Admitted();

					numServed++;

					delete patient;
				}
			}
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
