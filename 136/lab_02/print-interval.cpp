/*
Author: Kun Yu
Course: CSCI-136
Instructor: Michael Zamansky
Assignment: Lab2B

Print all integers from the requested interval
*/

#include<iostream>

void print_interval(int lower, int upper) {
	for (int i = lower; i < upper; i++) {
		std::cout << i << " ";
	}
}

int main() {
	std::cout << "Interval from -5 to 5\n";
	print_interval(-5,5);
	std::cout << "\nInterval from -5 to 10\n";
	print_interval(-5,10);
	std::cout << "\nInterval from 1 to 2\n";
	print_interval(1,2);
	return 0;
}