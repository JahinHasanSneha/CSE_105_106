#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    q.push(0);
    vector<int> visited(n, 0);
    visited[0] = 1;

    while (q.size() > 0)
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}