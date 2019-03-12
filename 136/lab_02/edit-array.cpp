/*
Author: Kun Yu
Course: CSCI-136
Instructor: Michael Zamansky
Assignment: Lab2C

Creates an array of 10 integers and provides the user with an interface to edit any of its elements.
*/

#include<iostream>
#include<string>

bool change_array(int arr[], int len, int i, int v) {
	if (i < len && i >= 0) {
		arr[i] = v;
		return false;
	}
	else {
		std::cout << "Index out of range. Exit.";
		return true;
	}		
}

void print_array(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << " ";
	}
}

bool check_input(std::string i, std::string v) {
	int num, num2;

	try {
		num = std::stoi(i);
		num2 = std::stoi(v);
	}
	catch (const std::invalid_argument& e) {
		return false;
	}
	return true;	
}

int main() {
	const int arr_size = 10;
	int myData[arr_size] = {1,1,1,1,1,1,1,1,1,1};
	int index, value;
	std::string index_str, value_str;
	bool valid_inputs = false;
	bool debug = true;

	if (!debug) {
		while (true) {
			print_array(myData, arr_size);
			std::cout << "\n\nInput index: ";
			std::getline (std::cin, index_str);
			std::cout << "Input value: ";
			std::getline (std::cin, value_str);
			std::cout << "\n";
			try {
				index = std::stoi(index_str);
				value = std::stoi(value_str);
			}
			catch (const std::invalid_argument& e) {
				std::cout << "Invalid Inputs. Exit.";
				break;
			}
			if (change_array(myData, arr_size, index, value)) {
				break;
			}
		}
	}
	else {
		int value_arr[10] = {5,10,15,20,25,30,35,40,45,50};
		for (int i = 0; i < 10; i++) {
			index = i;
			value = value_arr[i];			
			print_array(myData, arr_size);
			std::cout << "\n\nInput index: " << index <<"\n";
			std::cout << "Input value: " << value <<"\n";
			std::cout << "\n";
			change_array(myData, arr_size, index, value);
		}
		
		index = 10;
		value = 5;
		print_array(myData, arr_size);
		std::cout << "\n\nInput index: " << index <<"\n";
		std::cout << "Input value: " << value <<"\n";
		std::cout << "\n";
		if (change_array(myData, arr_size, index, value)) {
			std::exit;
		}
	}
	return 0;
}