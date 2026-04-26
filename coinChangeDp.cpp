#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
    {
        return 0;
    }
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= amount; a++)
        { // not take
            dp[i][a] = dp[i - 1][a];
            // take (unbounded)
            if (coins[i - 1] <= a && dp[i][a - coins[i - 1]]!= INT_MAX)
            {
                dp[i][a] = min(dp[i][a], dp[i][a - coins[i - 1]] + 1);
            }
        }
    
    }
    if (dp[n][amount] == INT_MAX)
    {
        return -1;
    }
    return dp[n][amount];
}
int main()
{

    // Static Input
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int ans = coinChange(coins, amount);

    cout << "Minimum coins needed = " << ans << endl;

    return 0;
}
