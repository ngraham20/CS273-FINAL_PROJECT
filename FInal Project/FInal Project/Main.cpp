//This is the main class that will be incharge of the UI
//It will allow the user to input 1)average hourly arrival time of new pataints 
// 2)number of doctors in the ER
// 3) the number of nurses in the ER
// It will output the average visit time
//WIll then allow the user to display all names of patients
// and also allow acces to a patients info based on his name
//ask the user if he wants to 1) close 2)rerun with the same numbers 3) rerun with new numbers
#include <string>;
#include <iostream>;
#include "HospitalSimulation.h"

using namespace std;
//returns true for a positive repsonse and fals for a negative one
bool getYNResponse(string question) {
	string r = "";
	bool input_loop = true;
	while (input_loop) {
		cout << question << endl;
		cout << "Enter (y/n)" << endl;
		cin >> r;
		if (r == "y" || r == "n") {
			input_loop = false;
		}
		else {
			cout << "Please enter either a (y) or a (n)" << endl;
		}
	}
	if (r == "y") {
		return true;
	}
	else {
		return false;
	}
}
int ui() {
	 //-------------------UI VERSION---------------------------
	bool run = true;
	while (run) {
		int arrival_rate;
		int total_docs;
		int total_nurses;
		int run_time = 10080; // 10080 min : 1 week
		double average;
		string response ="";

		cout << "Welcome to our Final Project" << endl;
		cout << "Brought to you by the minds of Christian, Nathanial, and Jude" << endl;
		cout << "Welcome to Sacred Heart's ER room" << endl;
		cout << "What is the hourly arrival rate of new patients?" << endl;
		cin >> arrival_rate;
		cout << "How many doctors are in?" << endl;
		cin >> total_docs;
		cout << "How many nurses are in" << endl;
		cin >> total_nurses;
		cout << "Ok running the simulation for one week" << endl;
		//run the simulation passing in the three values
		HospitalSimulation sim(arrival_rate, total_docs, total_nurses);
		sim.runSimulation(run_time);
		cout << "The average wait time is " << sim.getAverage() << endl;
		bool menu = true;
		while (menu) {
			if (getYNResponse("Do you want to print all names?")) {
				sim.printAllPatientNames();
			}
			bool search = true;
			while (search)
			{
				if (getYNResponse("Do you want to pull up someone's records?")) {
					cout << "Enter the name you want" << endl;
					cin >> response;
					sim.printRecordsByPatient(response);
				}
				if (getYNResponse("Do you want to stop searching or print all names again?")) {
					search = false;
				}
			}
			if (!getYNResponse("Do you want to print all names?")) {
				menu = false;
			}
		}
		


		cout << "Thank you for enduring this" << endl;
		cout << "Enter (c) to close" << endl;
		string close_response = "";
		cin >> close_response;
		if (close_response == "c") {
			run = false;
		}
	}
	return 0;
}
int testingZone() {
	// ----------------TESTING ZONE---------------------------
	int arrival_rate = 100; // one per hour = 168 patients (ish)
	int total_docs = 0;
	int total_nurses = 0;

	int overallAverage = 0;

	int cycles = 200;

	for (int i = 0; i < cycles; i++)
	{

		HospitalSimulation simulation(arrival_rate, total_docs, total_nurses);
		simulation.runSimulation(10080); // run the simulation for a week

		//cout << "The average wait time is " << simulation.getAverage() << endl;

		overallAverage += simulation.getNumArrived();
	}

	overallAverage /= cycles;
	cout << "The overall average patient Arrival is " << std::to_string(overallAverage) << endl;

	return 0;
}

int main() {
	//uncomment this for the final version
	ui();
	//testingZone();
	return 0;
}
