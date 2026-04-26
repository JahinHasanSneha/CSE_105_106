#include<bits/stdc++.h>
using namespace std;
int minimumOperations(vector<int> &nums)
{
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < nums.size(); i++)
    {if(nums[i]>0)
        p.push(nums[i]);
    }
    int count = 0;
    int prev = -1;

    while (p.size() > 0)
    {
     int x=p.top();
     p.pop();
     if(x!=prev)
     {
        count++;
        prev=x;
     }
    }
    return count;
}
