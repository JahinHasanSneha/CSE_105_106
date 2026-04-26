#include <bits/stdc++.h>
using namespace std;
int kthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < k; i++)
    {
        p.push(nums[i]);
    }
    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i]>p.top())
        {
            p.pop();
            p.push(nums[i]);
        }
    }
    return p.top();
}
int main()
{
    // Test case 1: k = 2
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << "The " << k1 << "-th largest element in [3,2,1,5,6,4] is: " 
         << kthLargest(nums1, k1) << endl;

    // Test case 2: k = 4 (duplicates)
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "The " << k2 << "-th largest element in [3,2,3,1,2,4,5,5,6] is: " 
         << kthLargest(nums2, k2) << endl;

    // Test case 3: k = 1 (largest element)
    vector<int> nums3 = {7, 10, 4, 3, 20, 15};
    int k3 = 1;
    cout << "The " << k3 << "-st largest element in [7,10,4,3,20,15] is: " 
         << kthLargest(nums3, k3) << endl;

    // Test case 4: k = size (smallest element)
    vector<int> nums4 = {1, 2, 3, 4, 5};
    int k4 = 5;
    cout << "The " << k4 << "-th largest element in [1,2,3,4,5] is: " 
         << kthLargest(nums4, k4) << endl;

    return 0;
}
