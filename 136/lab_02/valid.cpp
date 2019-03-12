/*
Author: Kun Yu
Course: CSCI-136
Instructor: Michael Zamansky
Assignment: Lab2A

Asks the user to enter an interger n, 0<n<100. Checks if user input meets criteria and prompts user to enter again if it does not.
*/

#include<iostream>
#include<string>

bool is_int(std::string str) {
	int num;

	try {
		num = std::stoi(str);
	}
	catch (const std::invalid_argument& e) {
		return false;
	}
	return true;
}

int main() {
	int i;
	bool out_of_bounds = false;
	std::string i_str;
	std::cout << "Please enter an interger: ";
	std::getline (std::cin, i_str);
	while (!(is_int(i_str)) || out_of_bounds) {
		std::cout << "Please re-enter: ";
		std::getline (std::cin, i_str);
		if (!(is_int(i_str))) {
			continue;
			out_of_bounds = false;
		}
		else {
			i = std::stoi(i_str);
			if (i <= 0 || i >= 100) {
				out_of_bounds = true;
			}
			else {
				break;
			}
		}
	}
	i = std::stoi(i_str);
	std::cout << "\nNumber squared is " << i*i;

	return 0;
}