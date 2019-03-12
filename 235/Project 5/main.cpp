#include <iostream>
#include <typeinfo>

#include "SortingTests.hpp"

int main() {

	size_t ARRAY_SIZE = 1000;
	int arr[ARRAY_SIZE];
	int arr2[ARRAY_SIZE];
	int arr3[ARRAY_SIZE];

	generateRandomArray(arr, ARRAY_SIZE);
	generateRandomArray(arr2, ARRAY_SIZE);
	generateRandomArray(arr3, ARRAY_SIZE);
	// generateAscendingArray(arr, ARRAY_SIZE);
	// generateDescendingArray(arr, ARRAY_SIZE);
	// generateLastTenRandomArray(arr, ARRAY_SIZE);
	// generateFewRandomArray(arr, ARRAY_SIZE);

	double run_time_avg = sortTest(&selectionSort, arr, ARRAY_SIZE);
	double run_time_avg_2 = sortTest(&insertionSort, arr2, ARRAY_SIZE);
	double run_time_avg_3 = mergeSortTest(arr3, ARRAY_SIZE);

	std::cout << "selectionSort: " << run_time_avg <<"\n";
	std::cout << "insertionSort: " << run_time_avg_2 <<"\n";
	std::cout << "mergeSort: " << run_time_avg_3 <<"\n";

	// int RETURN_SIZE = 15;

	// std::cout << "\n\n";

	// for (auto i = 0; i < ARRAY_SIZE; ++i) {
	// 	std::cout << arr[i] << "\t";
	// 	if ( (i+1) % RETURN_SIZE == 0 && i > 0) {
	// 		std::cout << "\n";
	// 	}
	// }

	// std::cout << "\n\n";

	// for (auto i = 0; i < ARRAY_SIZE; ++i) {
	// 	std::cout << arr2[i] << "\t";
	// 	if ( (i+1) % RETURN_SIZE == 0 && i > 0) {
	// 		std::cout << "\n";
	// 	}
	// }

	// std::cout << "\n\n";

	// for (auto i = 0; i < ARRAY_SIZE; ++i) {
	// 	std::cout << arr3[i] << "\t";
	// 	if ( (i+1) % RETURN_SIZE == 0 && i > 0) {
	// 		std::cout << "\n";
	// 	}
	// }

	// std::cout << "\n\n";
	
	return 0;
}