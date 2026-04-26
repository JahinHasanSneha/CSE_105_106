#include <bits/stdc++.h>
using namespace std;
int sequenceAlignment(string X,string Y)
{
    int n=X.size();
    int m =Y.size();
    int gap=-1;
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=i*gap;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=i*gap;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int match;
            if(X[i-1]==Y[j-1])
            {
                match=1;
            }
            else{
                match=-1;
            }
            dp[i][j]=max({dp[i-1][j-1]+match,dp[i-1][j]+gap,dp[i][j-1]+gap});

        }
    }
    return dp[n][m];
}
int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    cout << sequenceAlignment(X, Y) << endl;
}