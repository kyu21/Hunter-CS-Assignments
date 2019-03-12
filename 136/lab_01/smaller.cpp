
/*
Author: Kun Yu
Course: CSCI-136
Instructor: Professor Zamansky
Assignment: Lab1A

Asks the user to input two integer numbers and prints out the smaller of the two.
*/
#include <iostream>
int main() {
	int first_num, second_num;
	std::cout << "Enter the first number: ";
	std::cin >> first_num;
	std::cout << "Enter the second number: ";
	std::cin >> second_num;

	if (first_num < second_num) {
		std::cout << "\nThe smaller of the two is " << first_num << '\n';
	}
	else {
		std::cout << "\nThe smaller of the two is " << second_num;
	}
	return 0;
}
