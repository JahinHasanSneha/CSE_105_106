#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        priority_queue<int, vector<int>, greater<int>> p; // min‑heap
        for (int i = 0; i < m; i++) {
            p.push(nums1[i]);
        }
        for (int i = 0; i < n; i++) {
            p.push(nums2[i]);
        }
        int i = 0;
        while (!p.empty()) {
            nums1[i++] = p.top();
            p.pop();
        }
    }
};

int main() {
    // Example: merge two sorted arrays
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // size = 6, first 3 are elements
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int x : nums1) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}