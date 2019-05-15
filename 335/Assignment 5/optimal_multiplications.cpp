// Kun Yu
// Assignment 5
// Calculating Optimal ordering of matrix multiplcation

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "matrix.h"

using namespace std;
/**
* Compute optimal ordering of matrix multiplication.
* c contains the number of columns for each of the n matrices.
* c[ 0 ] is the number of rows in matrix 1.
* The minimum number of multiplications is left in m[ 1 ][ n ].
* Actual ordering is computed via another procedure using lastChange.
* m and lastChange are indexed starting at 1, instead of 0.
* Note: Entries below main diagonals of m and lastChange
* are meaningless and uninitialized.
*/
void optMatrix(const vector<int> &c, matrix<int> &m, matrix<int> &lastChange)
{
    int n = c.size() - 1;

    for (int left = 1; left <= n; ++left)
    {
        // Set diagonals to 0
        m[left][left] = 0;
    }

    // K is difference in ordering of two matrices
    for (int k = 1; k < n; ++k) // k is right - left
    {
        // left contains the left Matrix to consider
        for (int left = 1; left <= n - k; ++left)
        {
            // Gets all pairs of matrices whose numbering is k apart
            // For each position
            int right = left + k;
            m[left][right] = std::numeric_limits<int>::max();
            for (int i = left; i < right; ++i)
            {
                // Find the min of all possible pairs of matrices
                int thisCost = m[left][i] + m[i + 1][right] + c[left - 1] * c[i] * c[right];
                if (thisCost < m[left][right]) // Update min
                {
                    m[left][right] = thisCost;
                    lastChange[left][right] = i;
                }
            }
        }
    }
}

void parseFile(const string &filename, vector<int> & c) 
{
    ifstream file;
    file.open(filename);
    if (file.fail())
    {
        cout << "Unable to open file" << endl;
        exit(1);
    }

    string line;
    while (getline(file, line))
    {
        c.push_back(stoi(line));
    }
}

// Recursive function to print optimal ordering
void printOptimalOrder(int i, int j, matrix<int> &lastChange)
{
    if (i == j) {
        // -1 because lastChange is indexed starting at 1
        cout << static_cast<char>((i-1) + 65);
    }
    else {
        cout << "(";
        printOptimalOrder(i, lastChange[i][j], lastChange);
        printOptimalOrder(lastChange[i][j] + 1, j, lastChange);
        cout << ")";
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Error. Usage: " << argv[0] << " <DIMENSIONS_FILE>" << endl;
        return 0;
    }

    // Get filename and parse file for dimensions
    const string filename = argv[1];
    vector<int> c;
    parseFile(filename, c);

    // Calculate optimal number of multiplcations
    matrix<int> m(c.size(), c.size());
    matrix<int> lastChange(c.size(), c.size());
    optMatrix(c, m, lastChange);
    cout << "Optimal Number of Multiplications: " << m[1][c.size() - 1] << endl;

    //Extra Credit
    cout << "Optimal Ordering: ";
    printOptimalOrder(1, c.size()-1, lastChange);
    cout << endl;
}