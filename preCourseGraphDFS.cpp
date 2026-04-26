#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void dfs(int u, vector<vector<int>> &g, vector<int> &visited, int &count)
{
    visited[u] = 1;
    for (int v : g[u])
    {
        if (!visited[v])
        {
            count++;
            dfs(v, g, visited, count);
        }
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> rev(N+1);
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        rev[B].push_back(A);
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        int C;
        cin >> C;
        vector<int> visited(N+1, 0);
        int count = 0;
        dfs(C, rev, visited, count);
        cout << count << endl;
    }
    return 0;
}