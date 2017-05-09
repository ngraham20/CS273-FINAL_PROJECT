#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <random>

#include "Visit.h"
#include "Patient.h"
#include "Heap.h"


class HospitalSimulation
{
public:
	HospitalSimulation();
	~HospitalSimulation();

	void runSimulation(int time);

	std::vector<std::string> readPatients();
	Patient* pullPatient(int vectorIndex); // pulls a patient from vector into the heap
	void updateWaitingRoom(int clock); // updates the heap to check for patients
	void updateDoctors(int clock); // checks for available docs and uses them
	void updateNurses(int clock); // checks for available nurses and uses them
	void updateRegistrar(int clock); // if a patient is done, file a report
private:
	int numServed;
	cs172::Heap<Patient*> waitingRoom;
	std::vector<int> doctors;
	std::vector<int> nurses;
	std::map<std::string, Visit> registrar;
};

