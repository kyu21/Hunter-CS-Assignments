/*
Author: Kun Yu
Course: CSCI-136
Instructor: Professor Zamansky
Assignment: Lab1D

Asks the user to input a year and month and prints out the number of days of that year and month.
*/

#include <iostream>

bool isLeapYear(int year) {
	bool leapYear = false;

	if (year % 4 == 0) {
		leapYear = true;
		if ((year % 100 == 0) && (year % 400 != 0)) {
			leapYear = false; 
		}
	}

	return leapYear;
}

int main() {
	int month, year, mod_month, num_days;
	std::cout << "Enter year: ";
	std::cin >> year;
	std::cout << "Enter month: ";
	std::cin >> month;

	if (month > 7) {
		mod_month = month - 7;
	}
	if (mod_month % 2 == 0) {
		num_days = 30;
	}
	else {
		num_days = 31;
	}
	if (month == 2) {
		num_days = 28;
		if (isLeapYear(year)) {
			num_days = 29;
		}
	}

	std::cout << "\n" << num_days << " days";
	return 0;
}