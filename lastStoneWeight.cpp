#include <bits/stdc++.h>

using namespace std;
int lastStoneW8(int arr[], int n)
{
    priority_queue<int> p;
    for (int i = 0; i < n; i++)
    {
        p.push(arr[i]);
    }
    while (p.size() > 1)
    {
        int first = p.top();
        p.pop();
        int second = p.top();
        p.pop();
        int dest = abs(first - second);
        p.push(dest);

    }
    return p.top();
}
int main()
{
    int a[] = {2, 7, 4, 1, 8, 1};
    int n = sizeof(a) / sizeof(int);
    cout << lastStoneW8(a, n) << endl;
}
