#include <bits/stdc++.h>
using namespace std;
int findTargetSumWays(vector<int> &nums, int target)
{
    int total = 0;
    int n = nums.size();
    for (int x : nums)
    {
        total += x;
    }
    // impossible
    if (target > total)
    {
        return 0;
    }
    if ((target + total) % 2 != 0)
    {
        return 0;
    }
    int sum = (target + total) / 2;
    // Dp
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    // base
    dp[0][0] = 1;
    // fill table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            // not take
            dp[i][j] = dp[i - 1][j];
            // take
            if (nums[i - 1] <= j)
            {
                dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][sum];
}
int main()
{

    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << findTargetSumWays(nums, target) << endl;

    return 0;
}