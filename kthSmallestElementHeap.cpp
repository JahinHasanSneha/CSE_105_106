#include <bits/stdc++.h>
using namespace std;
int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> p;
    for (int i = 0; i < k; i++)
    {
        p.push(arr[i]);
    }
    for (int i = k; i < r; i++)
    {
        if (p.top() >arr[i])
        {
            p.pop();
          
            p.push(arr[i]);
         
        }
    }
    return p.top();
}
int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // find 3rd smallest
    // Note: The function expects l=0, r=n (since it uses r as the size)
    int result = kthSmallest(arr, 0, n, k);
    cout << "The " << k << "rd smallest element is: " << result << endl;
    return 0;
}