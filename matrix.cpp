#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

float vectorsDotProduct(const float *x, const float *y, int n)
{
    float res = 0.0;
    for (int i = 0; i < n; i++)
    {
        res += x[i] * y[i];
    }
    return res;
}

void multiplyMatrixAndVector(const float *rv_matrix_1st_row, const float *rv_vector, float *rv_result, int rv_rows, int rv_cols)
{ 
    for (int i = 0; i < rv_rows; i++)
    {
        rv_result[i] = vectorsDotProduct((rv_matrix_1st_row + i*rv_cols), rv_vector, rv_cols);
    }
}

int main(void) {
    const int row = 3;
    const int col = 4;
    float matrix[row][col]={{1,2,3,5},{4,5,6,10},{7,8,9,15}};
    float vec[col]={1,2,3,4};
    float result[row] = {};
    // cout << a << endl;
    multiplyMatrixAndVector(matrix[0], vec, result, row, col);
    return 0;
}
