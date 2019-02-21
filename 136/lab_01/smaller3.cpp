/*
Author: Kun Yu
Course: CSCI-136
Instructor: Professor Zamansky
Assignment: Lab1B

Asks the user to input three integer numbers and prints out the smaller of the three.
*/

#include <iostream>

int smaller (int num1, int num2) {
	if (num1 < num2) {
		return num1;
	}
	else {
		return num2;
	}
}

int main() {
	int first_num, second_num, third_num;
	std::cout << "Enter the first number: ";
	std::cin >> first_num;
	std::cout << "Enter the second number: ";
	std::cin >> second_num;
	std::cout << "Enter the third number: ";
	std::cin >> third_num;

	int smallest = smaller(smaller(first_num, second_num), third_num);
	std::cout << "\nThe smaller of the three is " << smallest;

	return 0;
}