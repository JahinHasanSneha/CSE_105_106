#include <bits/stdc++.h>
using namespace std;
int profitMax(vector<int> &A, int b)
{
    int sum = 0;
    priority_queue<int> p; // max Heap
    for (int i = 0; i < A.size(); i++)
    {
        p.push(A[i]);
    }
    while (b && p.size() > 0)
    {
        sum = sum + p.top();
        if (p.top() - 1)
            p.push(p.top() - 1);
        p.pop();
        b--;
    }
    return sum;
}
int main()
{
    vector<int> A = {2, 1, 4};
    int b = 4;

    cout << "Maximum Profit = " << profitMax(A, b) << endl;

    return 0;
}