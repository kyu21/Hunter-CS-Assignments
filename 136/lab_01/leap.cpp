/*
Author: Kun Yu
Course: CSCI-136
Instructor: Professor Zamansky
Assignment: Lab1C

Asks the user to input a year and prints out if the year is a leap year or not.
*/

#include <iostream>

int main() {
	int year;
	bool leapYear = false;
	std::cout << "Enter year: ";
	std::cin >> year;

	if (year % 4 == 0) {
		leapYear = true;
		if ((year % 100 == 0) && (year % 400 != 0)) {
			leapYear = false; 
		}
	}

	if (leapYear) {
		std::cout << "\nLeap Year";
	}
	else {
		std::cout << "\nCommon Year";
	}

	return 0;
}