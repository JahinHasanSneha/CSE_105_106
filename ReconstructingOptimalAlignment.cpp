#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void printAlignment(const string& A, const string& B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = (A[i-1] == B[j-1]) ? 0 : 1;
            dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + cost});
        }
    }

    // Backtrack
    string alignA, alignB;
    int i = n, j = m;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && dp[i][j] == dp[i-1][j-1] + (A[i-1] != B[j-1])) {
            alignA += A[i-1];
            alignB += B[j-1];
            i--; j--;
        } else if (i > 0 && dp[i][j] == dp[i-1][j] + 1) {
            alignA += A[i-1];
            alignB += '-';
            i--;
        } else { // j > 0
            alignA += '-';
            alignB += B[j-1];
            j--;
        }
    }
    reverse(alignA.begin(), alignA.end());
    reverse(alignB.begin(), alignB.end());
    cout << alignA << endl;
    cout << alignB << endl;
}

int main() {
    string A, B;
    cin >> A >> B;
    printAlignment(A, B);
    return 0;
}