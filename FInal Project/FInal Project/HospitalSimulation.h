#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <random>
#include <time.h>

#include "Visit.h"
#include "Heap.h"
#include "Doctor.h"
#include "Nurse.h"


class HospitalSimulation
{
public:
	//	HospitalSimulation();
	~HospitalSimulation();

	HospitalSimulation(int arrivalRate, int totalDoctors, int totalNurses);

	void runSimulation(int time);

	int getAverage();

	void printRecordsByPatient(std::string name); // prints all vitis of a given patient

	void printAllPatientNames(); // prints the *names* of ALL patents treated during simulation

	int getNumArrived();

private:
	//Cumulative statistics
	int numServed;
	int totalWaitTime;
	int numArrived;

	std::minstd_rand simpleRand;

	//The average number of patients that arrive during one hour
	int patientArrivalRate;

	std::vector<std::string> patientNames;

	cs172::Heap<Visit*> waitingRoomYellow;
	cs172::Heap<Visit*> waitingRoomRed;

	std::vector<Doctor*> doctors;
	std::vector<Nurse*> nurses;

	std::vector<Visit*> offices;

	std::map<std::string, std::vector<Visit*>> registrar; // map by string "patientName" to a vector of visits

	std::vector<std::string> readPatients();
	Visit* patientArrival(int clock); // creates a visit and adds it to the appropriate waiting room
	void updateWaitingRoom(int clock); // updates the heap to check for patients
	void updateDoctors(int clock); // checks for available docs and uses them
	void updateNurses(int clock); // checks for available nurses and uses them

	void addDoctor(); // adds a doctor to the vector
	void addNurse(); // adds a nurse to the vector


	void updateRegistrar(std::string patientName, Visit* visit); // file a report of all recent completed visits
};

