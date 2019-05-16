//Angela Lim
//Homework 5 Extra Credit
#ifndef PRINTOPTIMALPARENTHESIS_H
#define PRINTOPTIMALPARENTHESIS_H

#include <iostream>
#include <vector>
#include<stdio.h>
#include <string>
using namespace std;

//prints the optimal parenthesis for a matrix
void PrintOptimalParenthesis(int i, int j, int n,  int *parenthesis, char &matrix_name){
//if there's only one matrix in the current segment
    if(i == j){
      cout << matrix_name++;
      return;
    }
    cout << "(";
    //Recusrively put the parenthesis around subsegments from i to segement [i][j]
    PrintOptimalParenthesis(i, *((parenthesis + i * n)+ j), n, parenthesis, matrix_name);
    //Recusrively put parenthesis around segements from [i][j] to j
    PrintOptimalParenthesis(*((parenthesis + i * n)+ j) + 1, j, n, parenthesis, matrix_name);
    cout << ")";
  }



#endif
