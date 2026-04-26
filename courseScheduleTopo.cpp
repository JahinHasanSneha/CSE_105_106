#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;
class Solution
{
public:
    bool isCycleDFS(int src, vector<bool> &vis, vector<bool> &recPath,
                    vector<vector<int>> &edges)
    {
        vis[src] = true;
        recPath[src] = true;
        for (int i = 0; i < edges.size(); i++)
        {
            int v = edges[i][0];
            int u = edges[i][1];
            if (u == src)
            {
                if (!vis[v])
                {
                    if (isCycleDFS(v, vis, recPath, edges))
                    {
                        return true;
                    }
                }
                else if (recPath[v])
                {
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>> &edges)
    {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (isCycleDFS(i, vis, recPath, edges))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution s;

    // Test 1: No cycle -> can finish
    int n1 = 4;
    vector<vector<int>> edges1 = {
        {1, 0}, // to take 1 you need 0
        {2, 1},
        {3, 2}};
    cout << s.canFinish(n1, edges1) << endl; // expected: 1 (true)

    // Test 2: Cycle exists -> cannot finish
    int n2 = 2;
    vector<vector<int>> edges2 = {
        {1, 0},
        {0, 1}};
    cout << s.canFinish(n2, edges2) << endl; // expected: 0 (false)

    return 0;
}