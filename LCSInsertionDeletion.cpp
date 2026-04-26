#include <bits/stdc++.h>
using namespace std;
int editDistanceNoSub(const string &A, const string &B)
{
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int lcs = dp[n][m];
    return (n - lcs) + (m - lcs);//delete+insertion
    
}
int main()
{
    string A, B;
    cin >> A >> B;
    cout << editDistanceNoSub(A, B) << endl;
    return 0;
}