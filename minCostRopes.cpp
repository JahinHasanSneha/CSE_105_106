#include <bits/stdc++.h>
using namespace std;

int minCost(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < n; i++)
    {
        p.push(arr[i]);
    }
    int cost = 0;
    while (p.size() > 1)
    {
        int first = p.top();
        p.pop();
        int second = p.top();
        p.pop();
        int newrope = first + second;

        cost += newrope;
        p.push(newrope);
    }
    return cost;
}

int main()
{
    // Example: minimum cost to connect ropes
    int ropes[] = {4, 3, 2, 6};
    int n = sizeof(ropes) / sizeof(ropes[0]);

    int result = minCost(ropes, n);
    cout << "Minimum cost to connect all ropes: " << result << endl;

    // Another test
    int ropes2[] = {1, 2, 3, 4, 5};
    n = sizeof(ropes2) / sizeof(ropes2[0]);
    result = minCost(ropes2, n);
    cout << "Minimum cost for {1,2,3,4,5}: " << result << endl;

    return 0;
}