#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);

    for(int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    int sx = -1, sy = -1;

    // Find starting position S
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(grid[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }

    vector<vector<int>> visited(N, vector<int>(M, 0));
    queue<pair<int,int>> q;

    q.push(make_pair(sx, sy));
    visited[sx][sy] = 1;

    int exitCount = 0;

    // Direction arrays
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while(!q.empty()) {

        pair<int,int> current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {

                if(!visited[nx][ny] && grid[nx][ny] != '#') {

                    visited[nx][ny] = 1;
                    q.push(make_pair(nx, ny));

                    if(grid[nx][ny] == 'E') {
                        exitCount++;
                    }
                }
            }
        }
    }

    cout << exitCount << endl;

    return 0;
}
