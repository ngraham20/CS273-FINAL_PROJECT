#include "HospitalSimulation.h"



HospitalSimulation::HospitalSimulation()
{
}


HospitalSimulation::~HospitalSimulation()
{
}

void HospitalSimulation::runSimulation(int time)
{
	// reads all patients from the file into a vector
	std::vector<std::string> patients = readPatients();
	for (int i = 0; i < time; i++)
	{
		for (int i = 0; i < 100; i++)
		{

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
	while (!input.eof())
	{
		input >> word;
		if (word != "/n")
		{
			vec.push_back(word);
		}
	}
	return vec;
}

// this will alwasy pull a patient and push him/her into the heap
Patient * HospitalSimulation::pullPatient()
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
