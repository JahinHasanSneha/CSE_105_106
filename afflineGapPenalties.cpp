#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int affineAlignment(const string& A, const string& B, int gapOpen, int gapExt) {
    int n = A.size(), m = B.size();
    const int MATCH = 2, MISMATCH = -1;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<vector<int>> rowGap(n+1, vector<int>(m+1, 0)); // gap in A (row)
    vector<vector<int>> colGap(n+1, vector<int>(m+1, 0)); // gap in B (col)

    // Initialization
    for (int i = 1; i <= n; i++) {
        rowGap[i][0] = gapOpen + (i-1)*gapExt;
        dp[i][0] = rowGap[i][0];
    }
    for (int j = 1; j <= m; j++) {
        colGap[0][j] = gapOpen + (j-1)*gapExt;
        dp[0][j] = colGap[0][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int match = dp[i-1][j-1] + (A[i-1] == B[j-1] ? MATCH : MISMATCH);
            rowGap[i][j] = max(dp[i-1][j] + gapOpen, rowGap[i-1][j] + gapExt);
            colGap[i][j] = max(dp[i][j-1] + gapOpen, colGap[i][j-1] + gapExt);
            dp[i][j] = max({match, rowGap[i][j], colGap[i][j]});
        }
    }
    return dp[n][m];
}

int main() {
    int gapOpen, gapExt;
    cin >> gapOpen >> gapExt;
    string A, B;
    cin >> A >> B;
    cout << affineAlignment(A, B, gapOpen, gapExt) << endl;
    return 0;
}