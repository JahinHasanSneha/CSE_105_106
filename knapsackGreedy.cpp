#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2;
}
double fractionalKnapsack(int W, vector<pair<int, int>> &arr)
{
    sort(arr.begin(), arr.end(),cmp);
    double total = 0;
    for (auto &it : arr)
    {
        if (W >= it.second)
        {
            total += it.first;
            W -= it.second;
        }
        else
        {
            total += it.first * ((double)W / it.second);
            break;
        }
    }
    return total;
}
int main()
{
    vector<pair<int, int>> arr = {
        {60, 10}, {100, 20}, {120, 30}}; // {value, weight}

    int W = 50;

    cout << fractionalKnapsack(W, arr);
}