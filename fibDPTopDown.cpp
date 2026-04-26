#include <bits/stdc++.h>
using namespace std;
int fib(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return fib(n - 1, dp) + fib(n - 2, dp);
}
int main()
{
    int N; 
    cin >> N;
    vector<int> dp(N + 1, -1);
    cout << fib(N, dp);
}