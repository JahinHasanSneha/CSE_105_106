#include <bits/stdc++.h>
using namespace std;
// int primMST(int V, vector<vector<pair<int, int>>> adj)
// {
//     vector<bool> inMST(V, false);
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     pq.push({0, 0});
//     int mstCost = 0;
//     while (pq.size() > 0)
//     {
//         auto p = pq.top();
//         int wt = p.first;
//         int u = p.second;
//         pq.pop();
//         if (!inMST[u])
//         {
//             inMST[u] = true;
//             mstCost += wt;
//             for (int i = 0; i < adj[u].size(); i++)
//             {
//                 int v = adj[u][i].first;
//                 int w = adj[u][i].second;
//                 pq.push({w, v});
//             }
//         }
//     }
//     return mstCost;
// }
int primMST(int V, vector<vector<pair<int, int>>> &adj)
{
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    pq.push({0, 0}); // weight,node
    int total = 0;
    while (pq.size() > 0)
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if(inMST[node])
        {
            continue;
        }
        inMST[node] = true;
        total += wt;
        for (auto &nbr : adj[node])
        {
            int v = nbr.first;
            int weight = nbr.second;
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({weight, v});
            }
        }
    }
    return total;
}
int main()
{
    int V = 4;
    vector<vector<pair<int, int>>> adj(V);
    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});

    adj[0].push_back({3, 30});
    adj[3].push_back({0, 30});

    adj[1].push_back({2, 15});
    adj[2].push_back({1, 15});

    adj[2].push_back({3, 50});
    adj[3].push_back({2, 50});
    cout << "MInimum: " << primMST(V, adj) << endl;

    // Print the solution

    return 0;
}