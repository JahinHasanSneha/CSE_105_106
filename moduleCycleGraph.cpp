#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> g(N + 1);
    vector<int> indegree(N + 1, 0);

    // Build graph and compute indegree
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        g[A].push_back(B);
        indegree[B]++;
    }

    queue<int> q;

    // Push all nodes with indegree 0
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        count++;

        for(int v : g[u]) {
            indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if(count == N)
        cout << "No" << endl;   // No cycle
    else
        cout << "Yes" << endl;  // Cycle exists

    return 0;
}

