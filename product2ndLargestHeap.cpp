#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N;
    cin >> N;

    priority_queue<long long> pq; // max-heap

    for (int i = 0; i < N; i++)
    {
        long long x;
        cin >> x;
        pq.push(x);

        if ((int)pq.size() < 3)
        {
            cout << -1 << endl;
        }
        else
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long c = pq.top();
            pq.pop();

            cout << (a * b * c) << endl;

            
            pq.push(a);
            pq.push(b);
            pq.push(c);
        }
    }

    return 0;
}