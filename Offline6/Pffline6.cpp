#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>
#include <iomanip>

using namespace std;

struct Edge {
    int u, v;
    double dist;
};

struct City {
    int id;
    double x, y;
    
    bool operator<(const City& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

double distance(const City& a, const City& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// DFS-based approach to find MST (Minimum Spanning Tree)
void dfs(int u, vector<vector<pair<int, double>>>& adj, vector<bool>& visited, vector<Edge>& mstEdges, double& mstCost) {
    visited[u] = true;
    
    for (auto& edge : adj[u]) {
        int v = edge.first;
        double weight = edge.second;
        
        if (!visited[v]) {
            mstEdges.push_back({u, v, weight});
            mstCost += weight;
            dfs(v, adj, visited, mstEdges, mstCost);
        }
    }
}

vector<Edge> baseCase(vector<City>& base, double& cost) {
    int V = base.size();
    vector<Edge> result;
    vector<vector<pair<int, double>>> adj(V);
    
    // Create the graph with all edges (distances between cities)
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            double d = distance(base[i], base[j]);
            adj[i].push_back({j, d});
            adj[j].push_back({i, d});
        }
    }
    
    // Run DFS to find MST (instead of Prim's or Kruskal's)
    vector<bool> visited(V, false);
    double mstCost = 0;
    dfs(0, adj, visited, result, mstCost);
    
    cost += mstCost;
    return result;
}

vector<Edge> DnC(vector<City>& cities, int start, int end, int M, double& cost) {
    int n = end - start + 1;
    if (n <= M) {
        vector<City> base;
        base.reserve(n);
        for (int i = start; i <= end; i++) {
            base.push_back(cities[i]);
        }
        return baseCase(base, cost);
    }

    int mid = start + (end - start) / 2;
    
    // Divide into two halves and solve recursively
    vector<Edge> leftEdges = DnC(cities, start, mid, M, cost);
    vector<Edge> rightEdges = DnC(cities, mid + 1, end, M, cost);

    // Combine: check boundary edges between left and right
    double best = INT_MAX;
    int bestLeft = -1, bestRight = -1;
    for (int i = start; i <= mid; i++) {
        for (int j = mid + 1; j <= end; j++) {
            double d = distance(cities[i], cities[j]);
            if (d < best) {
                best = d;
                bestLeft = i;
                bestRight = j;
            }
        }
    }
    
    vector<Edge> finalResult = leftEdges;
    finalResult.insert(finalResult.end(), rightEdges.begin(), rightEdges.end());
    finalResult.push_back({cities[bestLeft].id, cities[bestRight].id, best});
    
    cost += best;
    return finalResult;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<City> cities(N);
    
    // Input the cities with their coordinates
    for (int i = 0; i < N; i++) {
        cin >> cities[i].id >> cities[i].x >> cities[i].y;
    }
    
    // Sort cities based on x and then y
    sort(cities.begin(), cities.end());
    
    double totalCost = 0.0;
    vector<Edge> edges = DnC(cities, 0, N - 1, M, totalCost);
    
    // Output the total cost and edges of the MST
    cout << fixed << setprecision(2);
    cout << "Total Cost: " << totalCost << endl;
    cout << "Edges:" << endl;
    
    for (auto& it : edges) {
        cout << it.u << " " << it.v << endl;
    }

    return 0;
}