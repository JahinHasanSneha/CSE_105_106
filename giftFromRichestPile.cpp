#include <bits/stdc++.h>
using namespace std;

long long pickGifts(vector<int> &gifts, int k)
{
    priority_queue<long long> p;

    long long rem = 0;
    for (int i = 0; i < gifts.size(); i++)
    {
        p.push(gifts[i]);
    }
    while (k-- && p.size() > 0)
    {
        long long top= p.top();
        p.pop();
       
        pq.push((long long)sqrt(top));
    }
    while (p.size() > 0)
    {
        rem += p.top();
        p.pop();
    }
    return rem;
}
int main()
{
}