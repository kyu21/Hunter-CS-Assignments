//Angela Lim
//CS 335
//Header file that includes the function that prints the parenthesis
//Second function finds the optimal number of multiplcation
#ifndef OPTMATRIX_H
#define OPTMATRIX_H

#include <limits>
#include "PrintOptimalParenthesis.h"
using namespace std;


//function that finds the optimal number of multiplication
int OptMatrix( const vector<int> & c, int n )
{   //Allocates one extra row and column but [0][0] isn't used
    int matrix[n][n];

    // Stores where the brackets are placed;
    int parenthesis[n][n];
    //for one matrix the cost is 0
    for(int i = 1; i < n; i++){
      matrix[i][i] = 0;
    }
    //@param l = chain length
    for(int length = 2; length < n; length++){
      for(int i = 1; i < n-length+1; i++){
        int j = i + length - 1;
        matrix[i][j] = std::numeric_limits<int>::max();
        for(int k = i; k <= j - 1; k++){
            //q is cost per scalar multiplication
          int q = matrix[i][k] + matrix[k+1][j] + c[i-1] * c[k] * c[j];
          if(q < matrix[i][j]){
            matrix[i][j] = q;
            //each [i,j] = k shows where to split the product array
            //i, i+i, ..., j is the optimal number of multiplications
            parenthesis[i][j] = k;
          }
        }
      }
    }
  char matrix_name = 'A';
  cout << "The optimal parenthetical ordering is : ";
  PrintOptimalParenthesis(1, n-1, n, (int *)parenthesis, matrix_name);
  cout << endl;
  return matrix[1][n-1];
}


#endif
