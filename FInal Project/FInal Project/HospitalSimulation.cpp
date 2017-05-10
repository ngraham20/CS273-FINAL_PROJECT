#include "HospitalSimulation.h"



HospitalSimulation::HospitalSimulation()
{
	numServed = 0;

	// initialize random seed
	srand(time(NULL));
}


HospitalSimulation::~HospitalSimulation()
{
}

void HospitalSimulation::runSimulation(int maxTime)
{
	// reads all patients from the file into a vector
	std::vector<std::string> patients = readPatients();

	for (int i = 0; i < maxTime; i++)
	{
		// update waiting room, doctors, nurses, and registrar
		updateWaitingRoom(i); // pulls patients into the waiting room
		updateDoctors(i); // updates doctors to do their jobs
		updateNurses(i); // updates nurses to do their jobs
		updateOffices(i); // updates offices to release the patients
	}
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

void HospitalSimulation::updateWaitingRoom(int clock)
{
	int count = 0;
	for (int i = 0; i < 100; i++) // loops 100 times for every tick of simulation time
	{
		int patientArrival = rand() % 100; // generates a random number between 0 and 99
		if (patientArrival == 1) // will only happen 1 out of 100 times (maybe)
		{
			count++; // increase the counter
			numServed++; // increases the total number of patients served
		}
	}
	for (int i = 0; i < count; i++) // will pull as many patients as arrived (calculated above)
	{
		patientArrival(numServed - 1); // pulls the patients from the vector and inserts him into the heap
	}
}

void HospitalSimulation::updateDoctors(int clock)
{
	for (int i = 0; i < doctors.size(); i++) // loop through all doctors
	{
		if (doctors.at(i) == 0) // the doctor will see you now
		{
			// TODO grab a patient (if available) from the heap and calculate the visit
			// TODO set the doctor's time to a number
		}
		else // the doctor is busy at the moment
		{
			doctors.at(i)--; // decrement the doctor's remainint time
		}
	}
}

void HospitalSimulation::updateNurses(int clock)
{
	for (int i = 0; i < nurses.size(); i++) // loop through all doctors
	{
		if (nurses.at(i) == 0) // the doctor will see you now
		{
			// TODO calculate the doctor's work time
			// TOD update the patient's visit list
			// TODO set the doctor's time to a number
		}
		else // the doctor is busy at the moment
		{
			nurses.at(i)--; // decrement the doctor's remainint time
		}
	}
}

void HospitalSimulation::updateOffices(int clock)
{
}

void HospitalSimulation::updateRegistrar(std::string patientName, Visit* visit) 
{ registrar[patientName] = visit; }
