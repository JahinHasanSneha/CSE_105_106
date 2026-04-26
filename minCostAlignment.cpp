#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Function to compute the minimum cost alignment using Dynamic Programming
pair<int, string> computeAlignment(const string &A, const string &B, int match, int mismatch, int gap) {
    int n = A.size();
    int m = B.size();

    // DP table to store the alignment scores
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the DP table
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i * gap;  // Gap penalty for deletions
    }

    for (int j = 0; j <= m; j++) {
        dp[0][j] = j * gap;  // Gap penalty for insertions
    }

    // Compute the DP values for alignment scores
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = (A[i - 1] == B[j - 1]) ? match : mismatch; // Match or Mismatch

            dp[i][j] = min({
                dp[i - 1][j] + gap,      // Deletion
                dp[i][j - 1] + gap,      // Insertion
                dp[i - 1][j - 1] + cost  // Substitution
            });
        }
    }

    // To build the alignment string
    string alignmentA = "", alignmentB = "";
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j] + gap) {
            alignmentA = A[i - 1] + alignmentA;  // Deletion
            alignmentB = "-" + alignmentB;
            i--;
        }
        else if (dp[i][j] == dp[i][j - 1] + gap) {
            alignmentA = "-" + alignmentA;  // Insertion
            alignmentB = B[j - 1] + alignmentB;
            j--;
        }
        else {
            alignmentA = A[i - 1] + alignmentA;  // Match or Mismatch
            alignmentB = B[j - 1] + alignmentB;
            i--;
            j--;
        }
    }

    // If there are remaining characters in A or B
    while (i > 0) {
        alignmentA = A[i - 1] + alignmentA;
        alignmentB = "-" + alignmentB;
        i--;
    }

    while (j > 0) {
        alignmentA = "-" + alignmentA;
        alignmentB = B[j - 1] + alignmentB;
        j--;
    }

    return {dp[n][m], alignmentA + "\n" + alignmentB};  // Return the score and the alignment path
}

int main() {
    string A, B;
    int match, mismatch, gap;

    // Take the input values
    cin >> match >> mismatch >> gap;
    cin.ignore();  // To ignore the newline after integer input
    getline(cin, A);  // Read the first string
    getline(cin, B);  // Read the second string

    // Call the computeAlignment function
    auto result = computeAlignment(A, B, match, mismatch, gap);

    // Output the results
    cout << "Minimum Cost Alignment Score: " << result.first << endl;
    cout << "Alignment Paths:" << endl;
    cout << result.second;

    return 0;
}
