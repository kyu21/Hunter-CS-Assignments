#include <iostream>
#include <string>

#include "def.h"

int main() {
    printRange(-2, 10);

    cout << sumRange(1, 3) << endl << endl;

    int size = 10;
    int *arr = new int[size]; // allocate array dynamically
    arr[0] = 12;
    arr[1] = 17;
    arr[2] = -5;
    arr[3] = 3;
    arr[4] = 7;
    arr[5] = -15;
    arr[6] = 27;
    arr[7] = 5;
    arr[8] = 13;
    arr[9] = -21;

    cout << sumArray(arr, size) << endl << endl;

    cout << boolalpha << isAlphanumeric("ABCD") << endl << endl;        // true (1)

    cout << boolalpha << nestedParens("((()))") << endl << endl;      // true (1)

    int prices [] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
    cout << boolalpha << divisible(prices, 9);
	return 0;
}