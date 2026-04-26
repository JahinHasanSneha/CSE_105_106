#include <bits/stdc++.h>
using namespace std;

int findParent(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u], parent);
}

void UnionByRank(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
    if (rank[pu] > rank[pv])
        parent[pv] = pu;
    else if (rank[pu] < rank[pv])
        parent[pu] = pv;
    else
    {
        parent[pv] = pu;
        rank[pu]++;
    }
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Min-heap of {weight, {u, v}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            // adj[i][j] is a vector of two ints: {neighbor, weight}
            int v = adj[i][j][0];
            int w = adj[i][j][1];
            pq.push({w, {i, v}});
        }
    }

    int cost = 0;
    while (!pq.empty())
    {
        auto [wt, edge] = pq.top(); pq.pop();
        int u = edge.first, v = edge.second;
        if (findParent(u, parent) != findParent(v, parent))
        {
            cost += wt;
            UnionByRank(u, v, parent, rank);
        }
    }
    return cost;
}

int main()
{
    int V = 4;
    // Create adjacency list: each element is a vector of vectors (each inner vector is {neighbor, weight})
    // We'll use vector of vector of vector<int>
    vector<vector<vector<int>>> adj(V);
    // Add edges (undirected)
    // Edge 0-1 weight 10
    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});
    // Edge 0-3 weight 30
    adj[0].push_back({3, 30});
    adj[3].push_back({0, 30});
    // Edge 1-2 weight 15
    adj[1].push_back({2, 15});
    adj[2].push_back({1, 15});
    // Edge 2-3 weight 50
    adj[2].push_back({3, 50});
    adj[3].push_back({2, 50});

    // Call spanningTree with adj.data() which is a pointer to the first element, i.e., vector<vector<int>>*
    int mstCost = spanningTree(V, adj.data());
    cout << "Minimum Cost: " << mstCost << endl; // Expected 55
    return 0;
}