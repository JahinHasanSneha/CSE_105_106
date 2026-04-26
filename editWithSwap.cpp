#include <bits/stdc++.h>
using namespace std;

int editDistanceWithSwap(const string& A, const string& B, int k) {
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX/2));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) dp[i][0] = i;
    for (int j = 1; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // insert, delete, substitute
            dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1,
                            dp[i-1][j-1] + (A[i-1] != B[j-1])});

            // Check for swap within last k positions
            // We look for a previous position in A and B such that swapping would match
            // Equivalent to: find a pair (i', j') within the window so that
            // A[i-1] == B[j'-1] and A[i'-1] == B[j-1] and the distance constraints hold.
            // We'll consider all pairs within a window of size k.
            for (int d = 2; d <= k; d++) {
                if (i >= d && j >= d) {
                    // try swapping A[i-1] with A[i-d] and B[j-1] with B[j-d]?
                    // Actually we want to swap characters in A (or B) to align.
                    // But standard Damerau–Levenshtein only swaps adjacent in both strings.
                    // For general swaps, we can allow matching when A[i-1] == B[j-d] and A[i-d] == B[j-1].
                    if (A[i-1] == B[j-d] && A[i-d] == B[j-1]) {
                        // This represents swapping the character at i-1 in A with the character at i-d in A,
                        // and similarly in B, resulting in a match after a single swap operation?
                        // Actually the cost for swapping two characters at distance d in one string is 1 if they are swapped in one operation.
                        // However, this operation is symmetric and we don't want to double count.
                        // We'll use the cost 1 to transition from dp[i-d][j-d] to dp[i][j] after the swap.
                        dp[i][j] = min(dp[i][j], dp[i-d][j-d] + 1);
                    }
                }
            }
        }
    }
    return dp[n][m];
}

int main() {
    int k;
    cin >> k;
    string A, B;
    cin >> A >> B;
    cout << editDistanceWithSwap(A, B, k) << endl;
    return 0;
}
