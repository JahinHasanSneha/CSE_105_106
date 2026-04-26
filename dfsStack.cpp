void iterativeDFS(map<char, vector<char>>& adj, char start) {
    map<char, bool> visited;
    stack<char> st;

    st.push(start);

    while (!st.empty()) {
        char u = st.top();
        st.pop();

        if (visited[u]) continue;
        visited[u] = true;

        cout << u << " ";

        // push in reverse alphabetical order
        for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
            char v = adj[u][i];
            if (!visited[v]) st.push(v);
        }
    }
}