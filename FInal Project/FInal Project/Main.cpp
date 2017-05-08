//This is the main class that will be incharge of the UI
//It will allow the user to input 1)average hourly arrival time of new pataints 
// 2)number of doctors in the ER
// 3) the number of nurses in the ER
// It will output the average visit time
//WIll then allow the user to display all names of patients
// and also allow acces to a patients info based on his name
//ask the user if he wants to 1) close 2)rerun with the same numbers 3) rerun with new numbers

<<<<<<< HEAD
int main()
{
	return 0;
}
=======
#include <string>;
#include <iostream>;

using namespace std;

int main() {
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



		cout << "Thank you for enduring this" << endl;
		cout << "Enter 1 to close" << endl;
		int close_response = 0;
		cin >> close_response;
		if (close_response == 1) {
			run = false;
		}
	}

}

>>>>>>> ee5014aa07f3d42de7545c285835fbb70045ec65
