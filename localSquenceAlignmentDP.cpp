#include <bits/stdc++.h>
using namespace std;
int main()
{
    int M, R, G;
    cin >> M >> R >> G;
    cin.ignore();
    string S;
    string T;
    getline(cin, S);
    getline(cin, T);
    int n = S.size();
    int m = T.size();
    int score = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (S[i - 1] == T[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + M;
            else
            {
                dp[i][j] = max({dp[i - 1][j] - G, dp[i][j - 1] - G, dp[i - 1][j - 1] - R, 0});
            }
            score = max(score, dp[i][j]);
        }
    }
    cout << "Maximum Alignment Score: " << score << endl;
}