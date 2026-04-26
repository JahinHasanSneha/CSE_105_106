#include <bits/stdc++.h>
using namespace std;
int knapsack(int W, vector<int> &wt, vector<int> &val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (wt[i - 1] > j) // vector 0 based that is why i-1
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i-1 ][j - wt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[n][W];
}

int main()
{
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {10, 40, 50, 70};
    int W = 8;

    cout << knapsack(W, wt, val, wt.size());
}