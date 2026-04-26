#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &price, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int ans = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, price[i - 1] + solve(n - i, price, dp));
    }

    return dp[n] = ans;
}

int cutRod(vector<int> &price, int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, price, dp);
}

int main()
{
    // price for rod length 1..8
    vector<int> price = {1,5,8,9,10,17,17,20};
    int n = 8;

    cout << "Maximum obtainable value = " << cutRod(price, n) << endl;

    return 0;
} 