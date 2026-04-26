#include <bits/stdc++.h>
using namespace std;
// Top down
//  int ways(int n, vector<int> &cost, vector<int> &dp)
//  {
//      if (n <= 1)
//      {
//          return 0;
//      }
//      if (dp[n] != -1)
//      {
//          return dp[n];
//      }
//      return dp[n] = min(cost[n - 1] + ways(n - 1, cost, dp), cost[n - 2] + ways(n - 2, cost, dp));
//  }
//  int minCostClimbingStairs(vector<int>&cost)
//  {
//      int n=cost.size();
//      vector<int>dp(n+1,-1);

//     return ways(n,cost,dp);
// }

// bottom up
// int minCostClimbingStairs(vector<int> &cost)
// {
//     int n = cost.size();
//     vector<int> dp(n + 1, -1);
//     dp[0] = 0;
//     dp[1] = 0;
//     for (int i = 2; i <= n; i++)
//     {
//         dp[i ] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
//     }
//     return dp[n];
// }
// OPtimum
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    int curr, prev = 0, prev1 = 0;

    for (int i = 2; i <= n; i++)
    {
        curr = min(cost[i - 1] + prev, cost[i - 2] + prev1);
        prev1 = prev;
        prev = curr;
    }
    return curr;
}
int main()
{
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost) << endl;
}
