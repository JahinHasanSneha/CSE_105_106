#include <bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string &A, string &B)
{
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string text1 = "abcde";
    string text2 = "ace";

    int ans = longestCommonSubsequence(text1, text2);

    cout << "Length of LCS = " << ans << endl;

    return 0;
}