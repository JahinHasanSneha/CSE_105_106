#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int I, D, R;
    cin >> I >> D >> R;

    cin.ignore();

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i * D;
    }

    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j * I;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min({
                    dp[i - 1][j] + D,
                    dp[i][j - 1] + I,
                    dp[i - 1][j - 1] + R
                });
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
            temp += s2[j - 1];
            op.push_back("Insert " + temp);
            j--;
        }
        else if (j == 0)
        {
            string temp = "";
            temp += s1[i - 1];
            op.push_back("Delete " + temp);
            i--;
        }
        else if (s1[i - 1] == s2[j - 1] && dp[i][j] == dp[i - 1][j - 1])
        {
            string temp = "";
            temp += s1[i - 1];
            op.push_back("Match " + temp);
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j] + D)
        {
            string temp = "";
            temp += s1[i - 1];
            op.push_back("Delete " + temp);
            i--;
        }
        else if (dp[i][j] == dp[i][j - 1] + I)
        {
            string temp = "";
            temp += s2[j - 1];
            op.push_back("Insert " + temp);
            j--;
        }
        else
        {
            string oldC = "";
            string newC = "";
            oldC += s1[i - 1];
            newC += s2[j - 1];

            op.push_back("Replace " + oldC + " with " + newC);
            i--;
            j--;
        }
    }

    reverse(op.begin(), op.end());

    cout << "Minimum Cost: " << dp[n][m] << endl;
    cout << "Operations:" << endl;

    for (string x : op)
    {
        cout << x << endl;
    }

    return 0;
}
