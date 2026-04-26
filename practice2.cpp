#include <bits/stdc++.h>
using namespace std;
int main()
{
    int I, D, R;
    cin >> I >> D >> R;
    cin.ignore();
    string S;
    string T;
    getline(cin, S);
    getline(cin, T);
    int n = S.size();
    int m = T.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i * D;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i * I;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S[i - 1] == T[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j] + D, dp[i][j - 1] + I, dp[i - 1][j - 1] + R});
            }
        }
    }
    vector<string> op;
    int i = n;
    int j = m;
    while (i > 0 || j > 0)
    {
        if (i == 0)
        {
            string temp = "";
            temp += T[j - 1];
            op.push_back("INsert " + temp);
            j--;
        }
        else if (j == 0)
        {
            string temp = "";
            temp += S[i - 1];
            op.push_back("Delete " + temp);
            i--;
        }
        else if (S[i - 1] == T[j - 1] && dp[i][j] == dp[i - 1][j - 1])
        {
            string temp = "";
            op.push_back("Match " + temp);
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j] + D)
        {
            string temp = "";
            temp += S[i - 1];
            op.push_back("Delete " + temp);
            i--;
        }
        else if (dp[i][j] == dp[i][j - 1])
        {
            string temp = "";
            temp += T[j - 1];
            op.push_back("Insert " + temp);
            j--;
        }
        else
        {
            string oldC = "";
            string newC = "";
            oldC += S[i - 1];
            newC += T[j - 1];
            op.push_back("Replace " + oldC + " with " + newC);
            i--;
            j--;
        }
    }
    reverse(op.begin(), op.end());
    cout << "Minimum cost:" << dp[n][m] << endl;
    cout << "Operations: " << endl;
    for (string x : op)
    {

        cout << x << endl;
    }
}