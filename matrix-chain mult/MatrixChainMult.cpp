#include "matrixchainmult.h"
#include <algorithm>
#include <climits>

using namespace std;

int matrixMultiplication(int N, int v[]) {
    // dp[i][j] stores the minimum cost to multiply matrices from index i to j
    int dp[501][501] = { 0 };

    // i represents the start index of the chain, moving backwards
    for (int i = N - 1; i >= 0; i--) {
        // j represents the end index of the chain, moving forwards
        // At least one matrix exists between i and j, so j starts from i + 2
        for (int j = i + 2; j < N; j++) {
            dp[i][j] = INT_MAX;

            // k is the split point between i and j
            for (int k = i + 1; k <= j - 1; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i] * v[k] * v[j]);
            }
        }
    }

    // Return the optimal cost for the entire chain from index 0 to N-1
    return dp[0][N - 1];
}