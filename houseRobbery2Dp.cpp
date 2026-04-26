#include <bits/stdc++.h>
using namespace std;
int Robbery(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    if (n == 2)
    {
        return max(nums[0], nums[1]);
    }
    int curr, prev = max(nums[0], nums[1]), prev2 = nums[0];
    for (int i = 2; i < n; i++)
    {
        curr = max(nums[i] + prev2, prev);
        prev2 = prev;
        prev = curr;
    }
    return curr;
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> arr1(n - 1);
    vector<int> arr2(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        arr1[i] = nums[i];
    }
    for (int i = 1; i < n; i++)
    {
        arr2[i - 1] = nums[i];
    }
    int curr1 = Robbery(arr1);
    int curr2 = Robbery(arr2);
    return max(curr1, curr2);
}
int main() {
    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter money in each house: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }


    int ans = rob(nums);

    cout << "Maximum money that can be robbed = " << ans << endl;

    return 0;
}