#include <bits/stdc++.h>
using namespace std;
// pair<dis,node>
vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int source)
{
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({0, source}); // dist,node
    while (pq.size() > 0)
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int d = it.first;
        for (auto &nbr : adj[node])
        {int v=nbr.first;
            int wt=nbr.second;
            if(dist[node]+wt<dist[v])
            {
                dist[v]=dist[node]+wt;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
int main()
{
    int V = 4;
    vector<vector<pair<int, int>>> adj(V);
    adj[0].push_back({1, 4}); // node,weight
    adj[0].push_back({2, 1});
    adj[1].push_back({0, 4});
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 5});
    adj[2].push_back({0, 1});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 3});
    adj[3].push_back({1, 5});
    adj[3].push_back({2, 3});
    int source = 0;
    vector<int> dist = dijkstra(V, adj, source);

    for (int i = 0; i < V; i++)
    {
        cout << "Node: " << i<< "->" << dist[i]<<endl;
    }
    return 0;
}