#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)

    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)

            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }
        while (!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();
            ans = max(ans, time);
            if (i - 1 >= 0 && !vis[i - 1][j] && grid[i - 1][j] == 1)
            {
                q.push({{i - 1, j}, time + 1});
                vis[i - 1][j] = true;
            }
            if (j - 1 >= 0 && !vis[i][j - 1] && grid[i][j - 1] == 1)
            {
                q.push({{i, j - 1}, time + 1});
                vis[i][j - 1] = true;
            }
            if (i + 1 < n && !vis[i + 1][j] && grid[i + 1][j] == 1)
            {
                q.push({{i + 1, j}, time + 1});
                vis[i + 1][j] = true;
            }
            if (j + 1 < m && !vis[i][j + 1] && grid[i][j + 1] == 1)
            {
                q.push({{i, j + 1}, time + 1});
                vis[i][j + 1] = true;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> grid1 = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};
    cout << s.orangesRotting(grid1) << endl; // expected: 4

    vector<vector<int>> grid2 = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1}};
    cout << s.orangesRotting(grid2) << endl; // expected: -1

    vector<vector<int>> grid3 = {
        {0, 2}};
    cout << s.orangesRotting(grid3) << endl; // expected: 0

    return 0;
}