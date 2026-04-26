#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;
struct Edge
{
    int u, v;
    double dist;
};
struct City
{
    int id;
    double x;
    double y;
    bool operator<(const City &other) const
    {
        if (x != other.x)
        {
            return x < other.x;
        }
        return y < other.y;
    }
};
double distance(City &a, City &b)
{
    double dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return dist;
}
double primMST(int V, vector<vector<pair<int, double>>> &adj, vector<int> &parent)
{
    parent.resize(V);
    for (int i = 0; i < V; ++i)
        parent[i] = -1;
    vector<double> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0.0, 0});
    key[0] = 0.0;
    double mstCost = 0;
    while (pq.size() > 0)
    {
        auto p = pq.top();
        pq.pop();
        double wt = p.first;
        int u = p.second;
        if (inMST[u])
        {
            continue;
        }
        inMST[u] = true;
        mstCost += wt;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            double w = adj[u][i].second;
            if (!inMST[v] && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }
    return mstCost;
}
vector<Edge> baseCase(vector<City> &base, double &cost)
{
    int V = base.size();
    vector<Edge> result;
    vector<vector<pair<int, double>>> adj(V);
    if (V <= 1)
    {
        return result;
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {

            double d = distance(base[i], base[j]);
            adj[i].push_back({j, d});
            adj[j].push_back({i, d});
        }
    }
    vector<int> parent;
    double c = primMST(V, adj, parent);
    cost = cost + c;

    for (int v = 1; v < V; v++)
    {
        int u = parent[v];
        double d = distance(base[u], base[v]);
        result.push_back({base[u].id, base[v].id, d});
    }
    return result;
}
vector<Edge> DnC(vector<City> &cities, int start, int end, int M, double &cost)
{
    int n = end - start + 1;
    if (n <= M)
    {
        vector<City> base;
        base.reserve(n);
        for (int i = start; i <= end; i++)
        {
            base.push_back(cities[i]);
        }

        return baseCase(base, cost);
    }
    int mid = start + (end - start) / 2;
    vector<Edge> leftEdges = DnC(cities, start, mid, M, cost);
    vector<Edge> rightEdges = DnC(cities, mid + 1, end, M, cost);
    double best = INT_MAX;
    int bestLeft = -1;
    int bestRight = -1;
    int leftStart = max(start, mid - M + 1);
    int rightEnd = min(mid + M, end);
    for (int i = leftStart; i <= mid; i++)
    {
        for (int j = mid + 1; j <= rightEnd; j++)
        {
            double d = distance(cities[i], cities[j]);
            if (d < best)
            {
                best = d;
                bestLeft = i;
                bestRight = j;
            }
        }
    }
    vector<Edge> finalResult = leftEdges;
    finalResult.insert(finalResult.end(), rightEdges.begin(), rightEdges.end());
    finalResult.push_back({cities[bestLeft].id, cities[bestRight].id, best});
    cost = cost + best;
    return finalResult;
}
int main()
{
    int N, M;
    cin >> N >> M;
    vector<City> cities(N);
    for (int i = 0; i < N; i++)
    {
        cin >> cities[i].id >> cities[i].x >> cities[i].y;
    }
    sort(cities.begin(), cities.end());
    double totalCost = 0.0;
    vector<Edge> edges = DnC(cities, 0, N - 1, M, totalCost);
    cout << fixed << setprecision(2);
    cout << "Total Cost: " << totalCost << endl;
    cout << "Edges:" << endl;
    for (auto &it : edges)
    {
        cout << it.u << " " << it.v << endl;
    }
}