#include <bits/stdc++.h>
using namespace std;

int minCostConnectPoints(vector<vector<int>> &points)
{
    int n = (int)points.size();
    vector<int> minDist(n, INT_MAX);
    vector<bool> inMST(n, false);

    minDist[0] = 0;
    long long mstCost = 0;

    for (int taken = 0; taken < n; taken++)
    {
        int u = -1;

        // pick the node not in MST with smallest minDist
        for (int i = 0; i < n; i++)
        {
            if (!inMST[i] && (u == -1 || minDist[i] < minDist[u]))
                u = i;
        }

        inMST[u] = true;
        mstCost += minDist[u];

        // update distances using u
        for (int v = 0; v < n; v++)
        {
            if (!inMST[v])
            {
                int w = abs(points[u][0] - points[v][0]) +
                        abs(points[u][1] - points[v][1]);
                if (w < minDist[v]) minDist[v] = w;
            }
        }
    }

    return (int)mstCost;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> points[i][0] >> points[i][1];

    cout << "Minimum Cost: " << minCostConnectPoints(points) << "\n";
    return 0;
}