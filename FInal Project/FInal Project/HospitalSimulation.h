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

	HospitalSimulation(int arrivalRate, int totalDoctors, int totalNurses);

	void runSimulation(int time);

	int getAverage();

	void printRecordsByPatient(std::string name); // prints all vitis of a given patient

	void printAllPatientNames(); // prints the *names* of ALL patents treated during simulation

private:
	int numServed;

	double patientArrivalRate;

	cs172::Heap<Patient*> waitingRoom;

	std::vector<int> doctors;
	std::vector<int> nurses;

	std::vector<Patient*> doctorsOffice;

	std::map<std::string, Visit*> registrar;

	std::vector<std::string> readPatients();
	Patient* patientArrival(std::vector<std::string>& patients, int vectorIndex); // pulls a patient from vector into the heap
	void updateWaitingRoom(std::vector<std::string>& patients, int clock); // updates the heap to check for patients
	void updateDoctors(int clock); // checks for available docs and uses them
	void updateNurses(int clock); // checks for available nurses and uses them
	void updateOffices(int clock); // checks for patients who have finished their visit and updates them

	void addDoctor(); // adds a doctor to the vector
	void addNurse(); // adds a nurse to the vector


	void updateRegistrar(std::string patientName, Visit* visit); // file a report of all recent completed visits
};

