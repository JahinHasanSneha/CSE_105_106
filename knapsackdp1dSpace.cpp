#include <bits/stdc++.h>
using namespace std;
int knapsack(int W, vector<int> &wt, vector<int> &val, int n)
{
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int w = W; w >=wt[i]; w--)
        {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    return dp[W];
}
int main()
{
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {10, 40, 50, 70};
    int W = 8;

    cout << knapsack(W, wt, val, wt.size());
}