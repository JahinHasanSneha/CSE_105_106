#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 4;
    int dist[4][4] = {
        {0, 3, 6, INT_MAX},
        {3, 0, INT_MAX, 2},
        {6, INT_MAX, 0, 1},
        {INT_MAX, 2, 1, 0}};
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}