// #include <bits/stdc++.h>
// using namespace std;
// int countways(int n)
// {
//     vector<int> dp(n + 1, -1);
//     dp[0] = 1;
//     dp[1] = 1;
//     dp[2] = 2;
//     for (int i = 3; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//     }
//     return dp[n];
// }
// int main()
// {
//     cout << countways(4);
// }
#include <bits/stdc++.h>
using namespace std;
int countways(int n)
{
    int curr, prev = 2, prev1 = 1, prev2 = 1;

    vector<int> dp(n + 1, -1);

    for (int i = 3; i <= n; i++)
    {
        curr = prev + prev1 + prev2;
        prev2 = prev1;
        prev1 = prev;
        prev = curr;
    }
    return curr;
}
int main()
{
    cout << countways(4);
}
