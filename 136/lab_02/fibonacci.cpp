/*
Author: Kun Yu
Course: CSCI-136
Instructor: Michael Zamansky
Assignment: Lab2D

Uses an array of ints to compute and print all Fibonacci numbers from F(0) to F(59).
*/

#include<iostream>

int main() {
	int fib[60];
	fib[0] = 0;
	fib[1] = 1;
	std::cout << fib[0] << "\n" << fib[1] << "\n";

	for (int i = 2; i < 60; i++) {
		fib[i] = fib[i-1] + fib[i-2];
		std::cout<< fib[i] << "\n";
	}

	return 0;
}

/* After 1836311903, the number becomes negative, which is due to the limitation of the integer class in c++. The largest positive integer is 2147483647 which is 1 less than 2^31 which in this case is reserved for 0. This is all due to the fact that signed integers are stored in 64 bits and so half are reserved for positive integers and when the program exceeds that limit, it starts going beyond, which incidently makes it count in a modular sense, resulting in negative numbers.*/