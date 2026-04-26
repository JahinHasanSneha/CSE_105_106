#include <bits/stdc++.h>
using namespace std;
pair<int, int> countAlignments(string &A, string &B)
{
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> cnt(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
        cnt[i][0] = 1;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
        cnt[0][j] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int cost = A[i - 1] == B[i - 1] ? 0 : 1;
            int del = dp[i - 1][j] + 1;
            int ins = dp[i][j - 1] + 1;
            int sub = dp[i - 1][j - 1] + cost;
            int minCost = min({del, ins, sub});
            dp[i][j] = minCost;
            int ways = 0;
            if (del == minCost)
                ways = ways + (cnt[i - 1][j]);
            if (ins == minCost)
                ways = ways + (cnt[i][j - 1]);
            if (sub == minCost)
                ways = (ways + cnt[i - 1][j - 1]);
                cnt[i][j]=ways;
        }
    }
    return {dp[n][m],cnt[n][m]};
}
int main()
{
    string A, B;
    cin >> A >> B;
    auto res = countAlignments(A, B);
    cout << res.second << endl; // print number of ways (you may also print distance)
    return 0;
}