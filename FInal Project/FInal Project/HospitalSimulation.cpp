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
	numArrived = 0;

	patientArrivalRate = arrivalRate;

	// initialize randomizer
	simpleRand.seed(time(NULL));

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
	this->offices = std::vector<Visit*>(totalDoctors + totalNurses, NULL);

}

void HospitalSimulation::runSimulation(int maxTime)
{
	// reads all patients from the file into a vector
	patientNames = readPatients();

	for (int time = 0; time < maxTime; time++)
	{
		//update waiting room, doctors, nurses, and registrar
		updateWaitingRoom(time); // pulls patients into the waiting room
		updateNurses(time); // updates nurses to do their jobs (before doctors, to be patient-efficient)
		updateDoctors(time); // updates doctors to do their jobs
	}
	std::cout << "Total number of patients arrived: " << numArrived << std::endl;
	std::cout << "Total number of patients served: " << numServed << std::endl;
	std::cout << "Total wait time: " << totalWaitTime << std::endl;
	return;
}

int HospitalSimulation::getAverage()
{
	return totalWaitTime / numServed;
}

void HospitalSimulation::printRecordsByPatient(std::string name)
{
	// TODO, Christian, this is yours too
	std::vector<Visit*> records = registrar[name];
	Visit* visit = nullptr;
	if (records.size() > 0) {
		//TODO format this
		std::cout << "All records for " << name << std::endl;
		std::cout << "Time In             Time Out                Attending               Severity" << std::endl;
		for (int ndx = 0; ndx < records.size(); ndx++) {
			visit = records[ndx];
			std::cout << "Time in:" << visit->Admitted() << "    Time out:" <<
				visit->Discharged() << "    Service was provided by :" <<
				visit->Provider() << "    Injury Severity:" <<
				visit->Severity() << "              " << std::endl;
		}
	}
}

void HospitalSimulation::printAllPatientNames()
{
	// TODO Christian, go ahead and do with this what you wil for the UI
	//Output all the keys of the registrar map. No sorting, no ordering
	for (std::map<std::string, std::vector<Visit*>>::const_iterator it = registrar.begin(); it != registrar.end(); it++)
	{
		std::cout << it->first << std::endl;
	}
}

int HospitalSimulation::getNumArrived()
{
	return numArrived;
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

// this will always pull a patient and push him/her into the heap
Visit* HospitalSimulation::patientArrival(int clock)
{
	//Patient* patient = new Patient(patients.at(index)); // creates a new patient based on the selected name
	Visit* visit = new Visit(clock);

	if (visit->Severity() > 10)
	{
		waitingRoomRed.push(visit); // adds the patient to the more severe waiting room
	}
	else {
		waitingRoomYellow.push(visit); //adds patient to the less severe waiting room
	}
	return visit;
}

void HospitalSimulation::updateWaitingRoom(int clock)
{
	int count = 0;
	for (int i = 0; i < 60; i++) // loops 60 times for every tick of simulation time (60s/min)
	{
		// patients have an hourly patientArrivalRate / 3600 of arriving in a given second
		int chance = 3600;
		int patientArrivalRoll = simpleRand() % chance; //value between 1 and 3600

		if (patientArrivalRoll < patientArrivalRate)
		{
			count++; // increase the counter
			//patientArrival(clock); // pulls the patients from the vector and inserts him into the heap
		}
	}
	for (int i = 0; i < count; i++) // will pull as many patients as arrived (calculated above)
	{
		patientArrival(clock); // pulls the patients from the vector and inserts him into the heap
		numArrived++;
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
				doc->decrementTime();
			}
			else if (doc->getRemainingTime() == 0)
			{
				// the doc is available

				Visit* visit = nullptr;
				if (waitingRoomRed.size() > 0) // if there are patients in the severe queue
				{
					visit = waitingRoomRed.pop(); // doc takes the patient
				}
				else if (waitingRoomYellow.size() > 0)
				{
					visit = waitingRoomYellow.pop();
				}
				if (visit != nullptr)
				{
					visit->Provider(doc->getName()); //Store  the medic ID as the care provider for the visit
					int workTime = doc->calculateWorkTime(clock); // calculates work time

					doc->setRemainingTime(workTime); // resets the doctor's timer

					visit->Discharged(clock + workTime); // updates the visit

					//Store the record of the patient's visit in the registrar
					int patientNameIndex = rand() % patientNames.size();
					std::string patientName = patientNames[patientNameIndex];
					updateRegistrar(patientName, visit); // adds the visit

					totalWaitTime += visit->Discharged() - visit->Admitted(); // updates the wait time

					numServed++; // increases the number served
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
				nurse->decrementTime();
			}
			else if (nurse->getRemainingTime() == 0)
			{
				// the nurse is available

				if (waitingRoomYellow.size() > 0) // if there are patients
				{
					Visit* visit = waitingRoomYellow.pop(); // nurse takes the patient

					visit->Provider(nurse->getName()); //Store  the medic ID as the care provider for the visit
					int workTime = nurse->calculateWorkTime(clock); // calculates work time

					nurse->setRemainingTime(workTime); // resets the nurse's timer
					visit->Discharged(clock + workTime); // updates the visit

					//Store the record of the patient's visit in the registrar
					int patientNameIndex = rand() % patientNames.size();
					std::string patientName = patientNames[patientNameIndex];
					updateRegistrar(patientName, visit); // adds the visit

					totalWaitTime += visit->Discharged() - visit->Admitted();

					numServed++;
				}
			}
		}
	}
}

//void HospitalSimulation::updateDoctors(int clock)
//{
//	for (int i = 0; i < doctors.size(); i++) // loop through all doctors
//	{
//		Doctor* doc = doctors.at(i);
//
//		if (doc->getRemainingTime() == 0) // the doctor will see you now
//		{
//			// first deal with the patient he's currently working with (if he is)
//			if (offices[i] != NULL) // has a patient
//			{
//				// first, add all patient's visits to registrar under the same name
//				Visit* currentPatient = offices[i];
//				currentPatient->Discharged(clock);
//
//				totalWaitTime += (currentPatient->Discharged() - currentPatient->Admitted());
//				numServed++;
//
//				offices[i] = NULL; // removes the patient from the offices
//			}
//
//			// then do whatever he wants
//			// grab a patient (if available) from the heap
//			Visit* newPatient = nullptr;
//			if (waitingRoomRed.size() > 0)
//			{
//				newPatient = waitingRoomRed.pop();
//
//			}
//			else if (waitingRoomYellow.size() > 0) {
//				newPatient = waitingRoomYellow.pop();
//			}
//			if (newPatient != nullptr) {
//				// calculate work time
//				int visitTime = doc->calculateWorkTime(clock);
//
//
//				// set doc's remaining time to work time
//				doc->setRemainingTime(visitTime);
//
//				//Store the record of the patient's visit in the registrar
//				int patientNameIndex = rand() % patientNames.size();
//				std::string patientName = patientNames[patientNameIndex];
//				registrar[patientName].push_back(newPatient);
//
//				// send the patient to the doctor's office
//				offices[i] = newPatient;
//			}
//		}
//		else // the doctor is busy at the moment
//		{
//			doctors.at(i)->decrementTime(); // decrement the doctor's remainint time
//		}
//	}
//}
//
//void HospitalSimulation::updateNurses(int clock)
//{
//	for (int i = 0; i < nurses.size(); i++) // loop through all nurses
//	{
//		Nurse* nurse = nurses.at(i);
//
//		if (nurse->getRemainingTime() == 0) // the nurse will see you now
//		{
//			// first deal with the patient he's currently working with (if he is)
//			if (offices[i + doctors.size()] != NULL) // has a patient in a nurse's office
//			{
//				// first, add all patient's visits to registrar under the same name
//				Visit* currentPatient = offices[i + doctors.size()];
//				currentPatient->Discharged(clock);
//
//				totalWaitTime += (currentPatient->Discharged() - currentPatient->Admitted());
//				offices[i + doctors.size()] = NULL; // removes the patient from the offices
//				numServed++;
//			}
//
//			// grab a patient (if available) from the heap
//			if (waitingRoomYellow.size() > 0)
//			{
//				Visit* newPatient = waitingRoomYellow.pop(); // pop the patient from the waiting room, then begin doing the same thing the doc would do
//							
//				int visitTime = nurse->calculateWorkTime(clock); // calculate work time
//
//				// set nurse's remaining time to work time
//				nurse->setRemainingTime(visitTime);
//
//				//Store the record of the patient's visit in the registrar
//				int patientNameIndex = rand() % patientNames.size();
//				std::string patientName = patientNames[patientNameIndex];
//				registrar[patientName].push_back(newPatient);
//
//				// send the patient to the nurse's office
//				offices[i + doctors.size()] = newPatient; // will ensure that nurses don't override doctor visits
//			}
//		}
//		else // the nurse is busy at the moment
//		{
//			nurses.at(i)->decrementTime(); // decrement the nurse's remaining time
//		}
//	}
//}

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
