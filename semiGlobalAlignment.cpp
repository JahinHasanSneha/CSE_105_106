#include <bits/stdc++.h>
using namespace std;
int semiGlobalAlignment(string &A, string &B)
{
    int n = A.size();
    int m = B.size();
    int match = 1;
    int mismatch = -1;
    int gap = -1;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int score = (A[i - 1] == B[j - 1]) ? match : mismatch;
            dp[i][j] = max({dp[i - 1][j] + gap, dp[i][j - 1] + gap, dp[i - 1][j - 1] + score});
        }
    }
    int best = 0;
    for (int j = 0; j <= m; j++)
    {
        best = max(best, dp[n][j]);
        return best;
    }
}
int main()
{
    string A, B;
    cin >> A >> B;
    cout << semiGlobalAlignment(A, B) << endl;
    return 0;
}