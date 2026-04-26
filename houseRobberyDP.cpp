#include <bits/stdc++.h>
using namespace std;
// top down
//  int Robbery(int index, vector<int> nums, vector<int> &dp)
//  {
//      if (index == 0)
//      {
//          return nums[0];
//      }
//      if (index == 1)
//      {
//          return max(nums[0], nums[1]);
//      }
//      if (dp[index] != -1)
//      {
//          return dp[index];
//      }
//      return dp[index] = max(nums[index] + Robbery(index - 2, nums, dp), Robbery(index - 1, nums, dp));
//  }
//  int rob(vector<int> &nums)
//  {
//      int n = nums.size();
//      vector<int> dp(n ,- 1);
//      return Robbery(n - 1, nums, dp);
//  }
// BottomUp
// int rob(vector<int> &nums, vector<int> &dp)
// {
//     int n = nums.size();
//     dp[0] = nums[0];
//     dp[1] = max(nums[0], nums[1]);
//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
//     }
//     return dp[n];
// }
// optimal
int rob(vector<int> &nums)
{
    int n = nums.size();
    int curr, prev = max(nums[0], nums[1]), prev2 = nums[0];
    for (int i = 2; i <= n; i++)
    {
        curr = max(nums[i] + prev2, prev);
        prev2 = prev;
        prev = curr;
    }
    return curr;
}
int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    cout << rob(nums);

    return 0;
}