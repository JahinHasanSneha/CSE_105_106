#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)

    {
        for (int w = 0; w <= W; w++)
        {
            if (wt[i-1] <= w)
            {
                dp[i][w] = max(dp[i][w], dp[i][w - wt[i - 1]] + val[i-1 ]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main()
{
   

    vector<int> val = {10,40,50,70};
    vector<int> wt  = {1,3,4,5};
    int capacity = 8;

    cout << knapSack(capacity,val,wt);

    return 0;
}