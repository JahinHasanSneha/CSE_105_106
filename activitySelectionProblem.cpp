#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int maxActivities(vector<pair<int, int>> &arr)
{
    sort(arr.begin(), arr.end());
    int count = 1;
    int lastEnd = arr[0].second;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i].first >= lastEnd)
        {
            count++;
            lastEnd = arr[i].second;
        }
    }
    return count;
}
int main()
{
    vector<pair<int, int>> arr = {
        {1, 3}, {2, 5}, {4, 6}, {6, 7}, {5, 8}, {8, 9}};

    cout << maxActivities(arr);
}