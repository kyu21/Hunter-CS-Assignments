/*
Author: Kun Yu
Course: CSCI-136
Instructor: Michael Zamansky
Assignment: Lab3

File I/O and Data Processing
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
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
	string line;
	getline(fin, line);
	while(fin >> date >> eastStorage >> eastElevation >> westStorage >> westElevation) {
		if (date == input_date){
			req_e_stor = eastStorage;
		}
	}
	fin.close();
	return req_e_stor;
}

double mineast() {
	string date;
	double min = 100.0;
	double eastStorage, eastElevation, westStorage, westElevation;
	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		cerr << "File cannot be opened for reading." << endl;
		exit(1); // exit if failed to open the file
	}
	string line;
	getline(fin, line);
	while(fin >> date >> eastStorage >> eastElevation >> westStorage >> westElevation) {
		if(eastStorage < min) {
			min = eastStorage;
		}
	}
	fin.close();
	return min;
}

double maxeast() {
	string date;
	double max = 0.0;
	double eastStorage, eastElevation, westStorage, westElevation;
	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		cerr << "File cannot be opened for reading." << endl;
		exit(1); // exit if failed to open the file
	}
	string line;
	getline(fin, line);	
	while(fin >> date >> eastStorage >> eastElevation >> westStorage >> westElevation) {
		if (max == 0.0) {
			max = eastStorage;
			continue;
		}
		if(eastStorage > max) {
			max = eastStorage;
		}
	}
	fin.close();
	return max;
}

string compare(string d1, string d2) {
	string ans = "";
	string date;
	double eastStorage, eastElevation, westStorage, westElevation;
	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		cerr << "File cannot be opened for reading." << endl;
		exit(1); // exit if failed to open the file
	}
	string line;
	getline(fin, line);
	while(fin >> date >> eastStorage >> eastElevation >> westStorage >> westElevation) {
		if (date >= d1 && date <= d2) {
			ans += date;
			if (eastElevation < westElevation) {
				ans += " West";
			}
			if (eastElevation > westElevation) {
				ans += " East";
			}
			if (eastElevation == westElevation) {
				ans += " Equal";
			}
			ans += "\n";
		}
	}
	fin.close();
	return ans;
}
string reverse_order(string d1, string d2) {
	string line;
	string ans = "";
	string date;
	double eastStorage, eastElevation, westStorage, westElevation;
	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		cerr << "File cannot be opened for reading." << endl;
		exit(1); // exit if failed to open the file
	}
	getline(fin, line);
	while(fin >> date >> eastStorage >> eastElevation >> westStorage >> westElevation) {
		if (date >= d1 && date <= d2) {
			string temp = date + " " + std::to_string(westElevation).substr(0,6) + " ft\n";
			ans.insert(0, temp);
		}
	}
	fin.close();
	return ans;
}