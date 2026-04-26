#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

bool match(int &a, int &b)
{
    char c;
    while (cin >> c)
    {
        if (c == '[')
        {
            break;
        }
    }
    if (!cin)
    {
        return false;
    }
    cin >> a;
    cin >> c;
    cin >> b;
    cin >> c;
    return true;
}
int main()
{

    int a, b;
    int n;
    cin >> n;
    set<pair<int, int>> played;
    vector<vector<int>> g(n);
    while (match(a, b))
    {
        if (a < 0 || b < 0 || a >= n || b >= n || a == b)
        {
            continue;
        }
        g[a].push_back(b);
        g[b].push_back(a);
        int u = min(a, b), v = max(a, b);
        played.insert({u, v});
    }
    vector<int> vis(n, 0);
    vector<vector<int>> group;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        queue<int> q;
        vector<int> compete;
        vis[i] = 1;
        q.push(i);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            compete.push_back(u);
            for (int j = 0; j < (int)g[u].size(); j++)
            {
                int v = g[u][j];
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        group.push_back(compete);
    }
    cout << group.size() << endl;
    for (int gi = 0; gi < group.size(); gi++)
    {
        vector<int> compete = group[gi];
        sort(compete.begin(), compete.end());
        cout << "Group " << (gi + 1) << ": {";
        for (int i = 0; i < compete.size(); i++)
        {
            cout << compete[i];
            if (i + 1 < compete.size())
            {
                cout << ", ";
            }
        }
        cout << "} | ";
        bool missing = false;
        for (int i = 0; i < (int)compete.size(); i++)
        {
            for (int j = i + 1; j < (int)compete.size(); j++)
            {
                int u = compete[i], v = compete[j];
                pair<int, int> e = make_pair(min(u, v), max(u, v));
                if (played.find(e) == played.end())
                {
                    if (missing)
                    {
                        cout << ", ";
                    }
                    cout << "[" << u << "," << v << "]";
                    missing = true;
                }
            }
        }

        if (!missing)
        {
            cout << "none";
        }
        cout << endl;
    }
    return 0;
}
