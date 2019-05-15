// Templated Matrix class provided by Textbook

#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iomanip>

using namespace std;

template <typename Object>
class matrix
{
public:
    // Constructors
    matrix(int rows, int cols) : array(rows)
    {
        for (auto &thisRow : array)
        {
            thisRow.resize(cols);
        }
    }
    matrix(vector<vector<Object>> v) : array{v} {}
    matrix(vector<vector<Object>> &&v) : array{std::move(v)} {}

    // Access Members
    const vector<Object> &operator[](int row) const
    {
        return array[row];
    }
    vector<Object> &operator[](int row)
    {
        return array[row];
    }

    // Get Data
    int numrows() const
    {
        return array.size();
    }
    int numcols() const
    {
        return numrows() ? array[0].size() : 0;
    }
    
    // Custom Function to print matrix to visualize how matrices were changing as algorithm progressed
    void printMatrix() const
    {
        for (int x = 1; x < array.size(); ++x) {
            cout << setw(6) << x;
        }
        cout << endl;
        for (size_t i = 1; i < array.size(); ++i) {
            cout << i << " ";
            for (size_t j = 1; j < array[0].size(); ++j) {
                cout << setw(6) << array[i][j];
            }
            cout << endl;
        }
    }

private:
    vector<vector<Object>> array;
};
#endif