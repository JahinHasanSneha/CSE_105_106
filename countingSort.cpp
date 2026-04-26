#include <bits/stdc++.h>
using namespace std;
void countingSort(vector<int> &A, vector<int> &B, int k)
{
    vector<int> C(k + 1, 0);
    // Step 1: Count frequencies
    for (int i = 0; i < A.size(); i++)
    {
        C[A[i]]++;
    }
    // Step 2: Prefix sum
    for (int i = 1; i <= k; i++)
    {
        C[i] += C[i - 1];
    }
    // Step 3: Build output (RIGHT → LEFT for stability)

    for (int i = A.size() - 1; i >= 0; i--)

    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}
int main()
{
    vector<int> A = {4, 2, 2, 8, 3, 3, 1};
    int n = A.size();

    int k = *max_element(A.begin(), A.end()); // maximum value

    vector<int> B(n); // output array

    countingSort(A, B, k);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << B[i] << " ";

    cout << endl;

    return 0;
}