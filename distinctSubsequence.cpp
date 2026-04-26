#include <iostream>
#include <vector>
#include <string>
using namespace std;

int numDistinct(string S, string T) {
    int m = S.size();
    int n = T.size();
    
    // DP table initialization
    vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));

    // Base case: an empty T can be formed from any prefix of S
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = 1;  // One way to form an empty T (by deleting all characters from S)
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];  // Include or exclude S[i-1]
            } else {
                dp[i][j] = dp[i - 1][j];  // Exclude S[i-1]
            }
        }
    }

    // The answer is in dp[m][n]
    return dp[m][n];
}

int main() {
    string S, T;
    cout << "Enter string S: ";
    cin >> S;
    cout << "Enter string T: ";
    cin >> T;

    int result = numDistinct(S, T);
    cout << "Number of distinct subsequences: " << result << endl;

    return 0;
}