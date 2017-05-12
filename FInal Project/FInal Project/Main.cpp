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

//// I commented this out simply for testing purposes. Will remove promptly
//int main()
//{
//	HospitalSimulation simulation;
//
//	simulation.readPatients();
//	simulation.runSimulation(5);
//
//	return 0;
//}

int ui() {
	 //-------------------UI VERSION---------------------------
	bool run = true;
	while (run) {
		int arrival_rate;
		int total_docs;
		int total_nurses;
		double average;

		cout << "Welcome to our Final Project" << endl;
		cout << "Brought to you by the minds of Christian, Nathanial, and Jude" << endl;
		cout << "Welcome to Sacred Heart's ER room" << endl;
		cout << "What is the hourly arrival time of new patients?" << endl;
		cin >> arrival_rate;
		cout << "How many doctors are in?" << endl;
		cin >> total_docs;
		cout << "How many nurses are in" << endl;
		cin >> total_nurses;
		cout << "Ok running the simulation for one week" << endl;
		//run the simulation passing in the three values
		cout << "Simulation was run" << endl;
		//display the menu here
		cout << "Enter a name whose records you want to see" << endl;

		//handle some garbage input and do some stuff

		//call the needed method to extract the proper records
		//print them 

		cout << "Thank you for enduring this" << endl;
		cout << "Enter 1 to close" << endl;
		int close_response = 0;
		cin >> close_response;
		if (close_response == 1) {
			run = false;
		}
	}
}
int testingZone() {
	// ----------------TESTING ZONE---------------------------
	int arrival_rate = 10;
	int total_docs = 5;
	int total_nurses = 6;
	HospitalSimulation simulation(arrival_rate, total_docs, total_nurses);
	simulation.runSimulation(120); // run the simulation for 2 hours (should get at least 1 or 2 patients)
}

int main() {
	//uncomment this for the final version
	//ui();
	testingZone();
}
