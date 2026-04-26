#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute the length of the Longest Common Subsequence (LCS)
int longestCommonSubsequence(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table for LCS
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];  // Return the length of LCS
}

// Function to construct the Shortest Common Super-sequence (SCS)
string shortestCommonSupersequence(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    int lcsLength = longestCommonSubsequence(X, Y);

    // Length of SCS is: |X| + |Y| - LCS length
    int scsLength = m + n - lcsLength;
    string scs = "";

    // Build the SCS string using LCS and the remaining characters from X and Y
    int i = m, j = n;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table for LCS
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to construct the SCS
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            scs = X[i - 1] + scs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            scs = X[i - 1] + scs;
            i--;
        } else {
            scs = Y[j - 1] + scs;
            j--;
        }
    }

    // Add remaining characters from X or Y
    while (i > 0) {
        scs = X[i - 1] + scs;
        i--;
    }
    while (j > 0) {
        scs = Y[j - 1] + scs;
        j--;
    }

    return scs;
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    // Construct SCS
    string scs = shortestCommonSupersequence(X, Y);
    cout << "Shortest Common Super-sequence: " << scs << endl;

    return 0;
}