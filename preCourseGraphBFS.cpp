#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // reversed graph
    vector<vector<int>> rev(N + 1);

    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        rev[B].push_back(A);   // reverse edge
    }

    int Q;
    cin >> Q;

    while(Q--) {
        int C;
        cin >> C;

        vector<int> visited(N + 1, 0);
        queue<int> q;

        visited[C] = 1;
        q.push(C);

        int count = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v : rev[u]) {
                if(!visited[v]) {
                    visited[v] = 1;
                    q.push(v);
                    count++;   // count prerequisite
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
