#include <iostream>
#include "matrixchainmult.h"

using namespace std;

int main() {
    // Test data representing dimensions of 5 matrices: 4x10, 10x3, 3x12, 12x20, 20x7
    int matrixDimensions[] = { 4, 10, 3, 12, 20, 7 };

    // Calculate the total number of elements in the array
    int N = sizeof(matrixDimensions) / sizeof(matrixDimensions[0]);

    // Output
    cout << "Minimum number of multiplications: " << matrixMultiplication(N, matrixDimensions) << endl;

    return 0;
}