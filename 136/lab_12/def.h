#include <iostream>
#include <string>

using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);
int sumArrayInRange(int *arr, int left, int right);
int sumArray(int *arr, int size);
bool isAlphanumeric(string s);
bool nestedParens(string s);
bool divisible_helper(int *prices, int size, int sum_one, int sum_two);
bool divisible(int *prices, int size);
