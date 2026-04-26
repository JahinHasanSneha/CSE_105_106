#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int globalAlignmentWithMatrix(string A, string B, vector<vector<int>> &scoreMatrix, int G) {
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; ++i) dp[i][0] = i * G;
    for (int j = 0; j <= m; ++j) dp[0][j] = j * G;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max({
                dp[i - 1][j - 1] + scoreMatrix[A[i - 1] - 'A'][B[j - 1] - 'A'],
                dp[i - 1][j] + G,
                dp[i][j - 1] + G
            });
        }
    }

    return dp[n][m];
}

int main() {
    string A = "ACGT", B = "AGT";
    vector<vector<int>> scoreMatrix = {
        {2, -1, -1, -1},
        {-1, 2, -1, -1},
        {-1, -1, 2, -1},
        {-1, -1, -1, 2}
    };  // Example scoring matrix for A, C, G, T
    int G = -2;  // Gap penalty
    cout << "Global Alignment Score: " << globalAlignmentWithMatrix(A, B, scoreMatrix, G) << endl;
}
