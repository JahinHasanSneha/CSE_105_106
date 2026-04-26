#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways in which frog can reach the top.

long long count(int n, vector<long long> &dp)
{
    if (n <= 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return count(n - 1,dp) + count(n - 2,dp) + count(n - 3,dp);
    // your code here
}
long long countWays(int n)
{
    vector<long long> dp(n + 3, -1);
    return count(n, dp);
}
int main()
{
    cout << countWays(4);
}