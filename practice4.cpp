#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int sum = 0;
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        // Read the array and calculate the nim sum
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum ^= a[i];
        }

        // Check if the product of n and k is even or odd
        if ((n * k) % 2 == 0) {
            cout << "YES" << endl;
        } else {
            // If the nim sum is odd, Shaunak can win, otherwise Yash wins
            cout << (sum % 2 == 1 ? "YES" : "NO") << endl;
        }
    }

    return 0;
}