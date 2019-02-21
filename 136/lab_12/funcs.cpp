#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>

#include "def.h"

using namespace std;

void printRange(int left, int right) {
  if (left != right + 1 && left < right) {
    cout << left << " ";
    printRange(left+1, right);
  }
  else {
    cout << right << endl << endl;
  }
}

int sumRange(int left, int right){
  if (left == right){
    return left;
  }
  return left + sumRange(left + 1, right);
}

int sumArrayInRange(int *arr, int left, int right){
  if (left == right && left <= right){
    return (arr)[left];
  }
  return (arr)[left] + sumArrayInRange(arr, left + 1, right);

}

int sumArray(int *arr, int size){
  return sumArrayInRange(arr, 0, size - 1);
}

bool isAlphanumeric(string s){
  if (s == ""){
    return true;
  }
  else if (isalnum(s[0])){
    return isAlphanumeric(s.substr(1, s.length()));
  }
  else{
    return false;
  }
} 

bool nestedParens(string s){
  if (s == ""){
    return true;
  }
  else if ((s[0] == '(' && s[s.length() - 1] == ')')){
    return nestedParens(s.substr(1, s.length()-2));;
  }
  return false;
}

bool divis_help(int *prices, int size, int sum1, int sum2){
  if (size == 0){
    return (sum1 == sum2);
  }
  else if(divis_help(prices, size - 1, sum1 + prices[size-1], sum2)){
    return true;

  }
  else if(divis_help(prices, size - 1, sum1, sum2 + prices[size-1])){
    return true;
  }
  return false;
}

bool divisible(int *prices, int size){
  int sum_ar = sumArray(prices, size);
  if (sum_ar % 2 != 0){
    return false;
  }
  return divis_help(prices,size, 0, 0);
}
