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

int ui() {
	 //-------------------UI VERSION---------------------------
	bool run = true;
	while (run) {
		int arrival_rate;
		int total_docs;
		int total_nurses;
		int run_time = 10080; // 10080 min : 1 week
		double average;
		string responce ="";

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

		cout << "Simulation was run" << endl;
		cout << "The average wait time is " << sim.getAverage() << endl;

		//do some nice menu print out stuff here
		//display the menu here
		sim.printAllPatientNames();
		cout << "Enter a name whose records you want to see" << endl;
		cin >> responce;
		//handle some garbage input and do some stuff
		
		//call the needed method to extract the proper records
		//print them 

		cout << "Thank you for enduring this" << endl;
		cout << "Enter 1 to close" << endl;
		string close_response = "";
		cin >> close_response;
		if (close_response == "x") {
			run = false;
		}
	}
	return 0;
}
int testingZone() {
	// ----------------TESTING ZONE---------------------------
	int arrival_rate = 1; // one per hour = 168 patients (ish)
	int total_docs = 5;
	int total_nurses = 6;
	HospitalSimulation simulation(arrival_rate, total_docs, total_nurses);
	simulation.runSimulation(10080); // run the simulation for a week

	cout << "The average wait time is " << simulation.getAverage() << endl;

	return 0;
}

int main() {
	//uncomment this for the final version
	//ui();
	testingZone();
	return 0;
}
