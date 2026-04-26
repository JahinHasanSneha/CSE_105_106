#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
int findParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}
void unionSet(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    parent[a] = b;
}
int main()
{
    int V = 4;
    vector<vector<int>> edges = {{10, 0, 1}, {30, 0, 3}, {15, 1, 2}, {50, 2, 3}};
    sort(edges.begin(), edges.end());  // {weight, u, v}
    parent.resize(V);
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }
    int mstCost = 0;
    for (auto &e : edges)
    {
        int w = e[0];
        int u = e[1];
        int v = e[2];
        if (findParent(u) != findParent(v))
        {
            mstCost += w;
            unionSet(u, v);
        }
    }
    cout << "Mst cost: " << mstCost << endl;
}