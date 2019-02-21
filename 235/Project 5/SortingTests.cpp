/*
	SortingTests.cpp

	This class implements 3 common sorting algorithms and functions 
	to test the 3 sorting algorthims.

	Sorting Algorithms:
		Selection Sort
		Insertion Sort
		Merge Sort

	Kun Yu
	CSCI 235 Fall 2018
	Project 5
*/


#include "SortingTests.hpp"

void selectionSort(int a[], size_t size) {
	// j is the current index for searching through numbers after current index
	// min stores the index of the smallest element in search
	int current_index, j, min;

	// loops through loop, selecting elements to go in indicies
	for (current_index = 0; current_index < size - 1; ++current_index) {

		// assumes the minimum is at current index. i.e. at correct location
		min = current_index;

		// loops through rest of array, searching for if there is an element smaller than current_index
		for (j = current_index + 1; j < size; ++j) {
			if (a[j] < a[min]) {
				min = j;
			}
		}

		// if current element is not in the right place (element smaller than it found), swap it
		if (min != current_index) {
			std::swap(a[min], a[current_index]);
		}
	}
}

void insertionSort(int a[], size_t size) {
	int i, j;

	// searches for correct place of current element
	for (i = 1; i < size; ++i) {
		j = i;

		// moves element one index behind until element before is smaller than current element
		while ((j > 0) && (a[j - 1] > a[j])) {
			std::swap(a[j], a[j - 1]);
			--j;
		}
	}

}

void merge(int arr[], int l, int m, int r) 
{
	//counter/location variables
    int i, j, k;

    // +1 cause there is 1 more item than index
    int leftArrSize = m - l + 1; 
    int rightArrSize =  r - m; 

    // temp arrays to represent the left and right half
    int *L = new int[leftArrSize]; 
    int *R = new int[rightArrSize];
  	
  	// copying entries into temp arrays
    for (i = 0; i < leftArrSize; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < rightArrSize; j++) 
        R[j] = arr[m + 1 + j]; 
 
 	// i,j are indexes of respective temp arrays
 	// k is index of merged array
    i = 0;
    j = 0;
    k = l;

    // iterates through temp arrays, comparing the next two elements in respective temp arrays
    while (i < leftArrSize && j < rightArrSize) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
 
 	// copies rest of temp arrays into merged array if any entries left
    while (i < leftArrSize) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    }
    while (j < rightArrSize) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }

    delete[] L;
    delete[] R;
} 

void mergeSort(int a[], int from, int to) {
	if (from < to) {
		int mid = (from + to) / 2;

		mergeSort(a, from, mid);
		mergeSort(a, mid + 1, to);

		merge(a, from, mid, to);
	}
}

void generateRandomArray(int values[], size_t size) {
	srand(static_cast<unsigned>(time(0)));

	for (auto i = 0; i < size; ++i) {
		values[i] = rand() % size;
	}
}

void generateAscendingArray(int values[], size_t size) {
	for (auto i = 0; i < size; ++i) {
		values[i] = i;
	}
}

void generateDescendingArray(int values[], size_t size) {
	for (auto i = 0; i < size; ++i) {
		values[i] = (size - 1) - i;
	}
}

void generateLastTenRandomArray(int values[], size_t size) {
	srand(static_cast<unsigned>(time(0)));

	for (auto i = 0; i < size; ++i) {
		if (i < size - 10) {
			values[i] = i;
		}
		else {
			values[i] = rand() % size;
		}
	}
}

void generateFewRandomArray(int values[], size_t size) {
	srand(static_cast<unsigned>(time(0)));

	for (auto i = 0; i < size; ++i) {
		values[i] = rand() % (size/10);
	}
}

double sortTest(void (*sortingFunction)(int a[], size_t size), int values[], size_t size) {
	double runtime_sum = 0;
	double runtime_avg;

	for (auto i = 0; i < 10; ++i) {
		auto start = high_resolution_clock().now();
		sortingFunction(values, size);
		auto end = high_resolution_clock().now();

		duration<float, std::micro> runt_time = duration_cast<microseconds>(end - start);
		runtime_sum += runt_time.count();
	}

	runtime_avg = runtime_sum / 10.00;

	return runtime_avg;
}

double mergeSortTest(int values[], size_t size) {
	double runtime_sum = 0;
	double runtime_avg;

	for (auto i = 0; i < 10; ++i) {
		auto start = high_resolution_clock().now();
		mergeSort(values, 0, size - 1);
		auto end = high_resolution_clock().now();

		duration<float, std::micro> runt_time = duration_cast<microseconds>(end - start);
		runtime_sum += runt_time.count();
	}

	runtime_avg = runtime_sum / 10.00;

	return runtime_avg;
}