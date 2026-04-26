#include <bits/stdc++.h>
using namespace std;

int sumBtwnTwokth(int arr1[], int N, int k1, int k2)
{
    priority_queue<int> p1; // size k1
    for (int i = 0; i < k1; i++)
        p1.push(arr1[i]);

    priority_queue<int> p2; // size (k2-1)
    for (int i = 0; i < k2 - 1; i++)
        p2.push(arr1[i]);

    // Maintain k1 smallest in p1 (max-heap)
    for (int i = k1; i < N; i++)
    {
        if (p1.top() > arr1[i])
        {
            p1.pop();
            p1.push(arr1[i]);
        }
    }

    // Maintain (k2-1) smallest in p2 (max-heap)
    for (int i = k2 - 1; i < N; i++)
    {
        if (p2.top() > arr1[i])
        {
            p2.pop();          
            p2.push(arr1[i]);  
        }
    }

    int sum1 = 0, sum2 = 0; 

    while (!p1.empty())
    {
        sum1 += p1.top();
        p1.pop();
    }

    while (!p2.empty())
    {
        sum2 += p2.top();
        p2.pop();
    }

    return sum2 - sum1;
}

int main()
{
    int arr[] = {1, 3, 12, 5, 15, 11};
    int N = sizeof(arr) / sizeof(arr[0]);

    int k1 = 3;
    int k2 = 6;

    cout << "Sum between " << k1 << "th and "
         << k2 << "th smallest elements = "
         << sumBtwnTwokth(arr, N, k1, k2) << endl;

    return 0;
}