/*
Author: Kun Yu
Course: CSCI-136
Instructor: Michael Zamansky
Assignment: Lab3 PreLab
File I/O and Data Processing
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

double east_storage(string input_date) {
	string date;
	double eastStorage, eastElevation, westStorage, westElevation;
	double req_e_stor;
	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		cerr << "File cannot be opened for reading." << endl;
		exit(1); // exit if failed to open the file
	}

	string junk;
	getline(fin, junk);
	while(fin >> date >> eastStorage >> eastElevation >> westStorage >> westElevation) {
		if (date == input_date){
			req_e_stor = eastStorage;
		}
	}
	fin.close();
	return req_e_stor;
}

int main() {
	cout << east_storage("01/01/2016") << "\n";
	return 0;
}