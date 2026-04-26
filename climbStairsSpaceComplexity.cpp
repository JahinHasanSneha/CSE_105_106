#include <bits/stdc++.h>
using namespace std;
int climbStairs(int n)
{
    vector<int> dp(n + 2, -1);
    int curr, next = 1, next2 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        curr = next + next2;
        next2 = next;
        next = curr;
    }
    return curr;
}
int main()
{
    cout << climbStairs(7);
}