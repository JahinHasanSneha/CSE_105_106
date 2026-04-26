#include <bits/stdc++.h>
using namespace std;

void dfs(char start, map<char, vector<char>> &adj) {

    map<char, int> color;   // 0 = WHITE, 1 = GRAY, 2 = BLACK
    map<char, int> disc;
    int time = 0;

    stack<pair<char, int>> st;  // {node, next neighbor index}

    // start node
    st.push({start, 0});
    color[start] = 1; // GRAY
    disc[start] = ++time;

    while (!st.empty()) {

        char u = st.top().first;
        int &i = st.top().second;  // index of next neighbor

        // if still has neighbors
        if (i < adj[u].size()) {

            char v = adj[u][i];
            i++;  // move to next neighbor

            if (color[v] == 0) {
                cout << u << " -> " << v << " : tree edge\n";

                color[v] = 1; // GRAY
                disc[v] = ++time;

                st.push({v, 0});
            }
            else if (color[v] == 1) {
                cout << u << " -> " << v << " : back edge\n";
            }
            else {
                if (disc[u] < disc[v])
                    cout << u << " -> " << v << " : forward edge\n";
                else
                    cout << u << " -> " << v << " : cross edge\n";
            }
        }
        else {
            // done with this node
            color[u] = 2; // BLACK
            st.pop();
        }
    }
}