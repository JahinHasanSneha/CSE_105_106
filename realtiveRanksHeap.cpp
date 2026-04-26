#include <bits/stdc++.h>
using namespace std;
vector<string> findRelativeRanks(vector<int> &score)
{
    priority_queue<pair<int, int>> p;
    for (int i = 0; i < score.size(); i++)
    {
        p.push({score[i], i});
    }
    vector<string> ans(score.size());
    int rank = 1;

    while (!p.empty())
    {
        int idx = p.top().second;
        p.pop();
        if (rank == 1)
        {
            ans[idx] = "Gold Medal";
        }
        else if (rank == 2)
        {
            ans[idx] = "Silver Medal";
        }
        else if (rank == 3)
        {
            ans[idx] = "Bronze Medal";
        }
        else
        {
            ans[idx] = to_string(rank);
        }
        rank++;
    }
    return ans;
}
int main()
{
    vector<int> score = {5, 4, 3, 2, 1};
    vector<string> here = findRelativeRanks(score);
    for (string st : here)
    {
        cout << st << " ";
    }
}