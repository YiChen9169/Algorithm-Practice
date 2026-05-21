#include "LCS.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solveLCS(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();

    // Create a 2D vector c with dimensions (m+1) x (n+1), initialized to 0
    // c[i][j] stores the length of the LCS of prefix X[0..i-1] and prefix Y[0..j-1]
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

    // 1. Fill the table using Bottom-Up Dynamic Programming
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                // If characters match, add 1 to the result of the diagonal subproblem
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else {
                // If characters do not match, take the maximum value from the top or left cell
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    cout << "LCS Length: " << c[m][n] << endl;

    // 2. Construct the actual LCS string using Backtracking
    string lcs_str = "";
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            // Character is part of the LCS. Append it and move diagonally up-left
            lcs_str.push_back(X[i - 1]);
            i--;
            j--;
        }
        else if (c[i - 1][j] >= c[i][j - 1]) {
            // The value from the top cell is greater or equal; move upwards
            i--;
        }
        else {
            // The value from the left cell is greater; move leftwards
            j--;
        }
    }

    // Since the characters were collected in reverse order, reverse the string back
    reverse(lcs_str.begin(), lcs_str.end());

    cout << "LCS String: " << (lcs_str.empty() ? "(No common subsequence)" : lcs_str) << endl;
}