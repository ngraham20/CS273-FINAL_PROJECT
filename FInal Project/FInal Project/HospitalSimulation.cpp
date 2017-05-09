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
			pullPatient(numServed-1); // pulls the patients from the vector and inserts him into the heap
		}
		updateWaitingRoom(i);
		updateDoctors(i);
		updateNurses(i);
		updateRegistrar(i);
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
Patient * HospitalSimulation::pullPatient(int index)
{
	return nullptr;
}

void HospitalSimulation::updateWaitingRoom(int clock)
{
}

void HospitalSimulation::updateDoctors(int clock)
{
}

void HospitalSimulation::updateNurses(int clock)
{
}

void HospitalSimulation::updateRegistrar(int clock)
{
}
