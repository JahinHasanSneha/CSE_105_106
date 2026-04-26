#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u, int v)

    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    bool isCycleUndirBFS(int src, vector<bool> &vis)
    {
        queue<pair<int, int>> q;
        q.push({src, -1});
        vis[src] = true;
        while (q.size() > 0)
        {
            int u = q.front().first;
            int parU = q.front().second;
            q.pop();

            for (int v : l[u])
            {
                if (!vis[v])
                {
                    q.push({v, u});
                    vis[v] = true;
                }
                else if (v != parU)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle()
    {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (isCycleUndirBFS(i, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    cout << g.isCycle() << endl;
    return 0;
}