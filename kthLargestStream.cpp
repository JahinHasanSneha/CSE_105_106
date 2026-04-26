#include <bits/stdc++.h>
using namespace std;
vector<int> kthLargest(int k, int n, int arr[])
{
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < n; i++)
    {
        p.push(arr[i]);
        if (p.size() > k)
        {
            p.pop();
        }
        if (p.size() < k)
        {
            result.push_back(-1);
        }
        else
        {
            result.push_back(p.top());
        }
    }
    return result;
}
int main() {
    // Example 1
    int k = 4;
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> ans = kthLargest(k, n,arr);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    // Example 2
    k = 3;
    int arr2[] = {5, 1, 3, 4, 2};
    n = sizeof(arr2) / sizeof(arr2[0]);
    ans = kthLargest(k, n,arr2);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
