#include <bits/stdc++.h>
using namespace std;
int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int w = W; w >= wt[i]; w--)
        {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}
int main()
{

    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;

    cout << knapsack(W, val, wt);

    return 0;
}