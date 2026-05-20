#include <iostream>
#include <vector>
#include "AssemblyLine.h"

using namespace std;

int main() {
    int n = 4;
    vector<vector<int>> a = { {4, 5, 3, 2}, {2, 1, 6, 5} };
    vector<vector<int>> t = { {2, 1, 3}, {1, 2, 2} };
    int e[2] = { 2, 4 };
    int x[2] = { 3, 2 };

    AssemblyLineScheduling(n, a, t, e, x);

    return 0;
}