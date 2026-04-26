#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
   
    cin >> M >> N;
    vector<int> seat(M);
    for (int i = 0; i < M; i++)
    {
        cin >> seat[i];
    }
    int sum = 0;
    priority_queue<int> p;
    for (int i = 0; i < M; i++)
    {
        p.push(seat[i]);
    }
    while (p.size() > 0 && N > 0)
    {
        int top = p.top();
        p.pop();
        if (top > 1)
        {
            p.push(top-1);
        }

        sum = sum + top;
        N--;
    }
    cout << sum << endl;
}