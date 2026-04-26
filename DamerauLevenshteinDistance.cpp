#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int damerauLevenshtein(const string& A, const string& B) {
    int n = A.size();
    int m = B.size();
    // dp[i][j] = min distance between first i chars of A and first j chars of B
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base cases
    for (int i = 0; i <= n; ++i) dp[i][0] = i; // delete all from A
    for (int j = 0; j <= m; ++j) dp[0][j] = j; // insert all into A

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cost = (A[i-1] == B[j-1]) ? 0 : 1; // substitution cost
            // Standard Levenshtein operations
            int del = dp[i-1][j] + 1;               // delete from A
            int ins = dp[i][j-1] + 1;               // insert into A
            int sub = dp[i-1][j-1] + cost;          // substitute
            dp[i][j] = min({del, ins, sub});

            // Transposition: if last two characters of A and B are swapped
            if (i > 1 && j > 1 && A[i-1] == B[j-2] && A[i-2] == B[j-1]) {
                int trans = dp[i-2][j-2] + 1;       // swap adjacent pair
                dp[i][j] = min(dp[i][j], trans);
            }
        }
    }
    return dp[n][m];
}

int main() {
    string A, B;
    cin >> A >> B;
    cout << damerauLevenshtein(A, B) << endl;
    return 0;
}