#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> candies(N);
    for (int i = 0; i < N; i++)
    {
        cin >> candies[i];
    }
    int sum = 0;
    priority_queue<int> p;
    for (int i = 0; i < N; i++)
    {
        p.push(candies[i]);
    }
    while(K && p.size()>0)
    {
        int top=p.top();
        p.pop();
        sum+=top;
        p.push(floor(top/2));
        K--;
    }
    cout<<sum<<endl;
}
