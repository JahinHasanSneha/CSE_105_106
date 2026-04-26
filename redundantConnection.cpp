#include <bits/stdc++.h>
using namespace std;
vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int pu = u; // Find root of u
        while (parent[pu] != pu)
        {
            pu = parent[pu];
        }
        int pv = v; // Find root of v
        while (parent[pv] != pv)
        {
            pv = parent[pv];
        }
        if(pu==pv)
        {
            return edges[i];
        }
        parent[pu]=pv;
    }
    return {};
}
int main() {
    int n;
    cin >> n;

    vector<vector<int>> edges(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> result = findRedundantConnection(edges);

    cout << "Redundant Edge: ";
    cout << result[0] << " " << result[1] << endl;

    return 0;
}