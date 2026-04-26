#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> g(1000);

    for (int i = 0; i < N; i++)
    {
        string s, z;
        cin >> s >> z;

        int a = s[1] - 'A';
        int b = z[0] - 'A';
        g(a).push_back(b);
    }
    vector<bool> vis(26, false);
    queue<pair<int, int>> q;
    q.push({0, 1});
    vector<pair<int, int>> ans;

    while (q.size() > 0)
    {
        int x = q.front();

        q.pop();

        if (vis[x.first] == 1)
        {
            continue;
        }
        vis[x.frist] = 1;
        if (g[x.first.size()] == 1)
        {
            ans.push_back({g[x.first][0], x.second + 1});
        }
        for (int v : g[x.first])
        {
            q.push({v, x.second + 1});
        }
    }
    cout << ans.size() << endl;
    for (int x : ans)
    {
        cout << (char)(x.first + 'A') << " " << x.second << endl;
    }
    return 0;
}