#include <bits/stdc++.h>
using namespace std;

// Counting sort based on digit (exp = 1, 10, 100...)
void countingSort(vector<int>& A, int exp)
{
    int n = A.size();
    vector<int> B(n);
    vector<int> C(10, 0); // digits 0–9

    // Count occurrences
    for (int i = 0; i < n; i++)
        C[(A[i] / exp) % 10]++;

    // Prefix sum
    for (int i = 1; i < 10; i++)
        C[i] += C[i - 1];

    // Build output (right → left for stability)
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (A[i] / exp) % 10;
        B[C[digit] - 1] = A[i];
        C[digit]--;
    }

    // Copy back
    for (int i = 0; i < n; i++)
        A[i] = B[i];
}

// Radix Sort
void radixSort(vector<int>& A)
{
    int maxVal = *max_element(A.begin(), A.end());

    // Process each digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(A, exp);
}

int main()
{
    vector<int> A = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(A);

    cout << "Sorted array: ";
    for (int x : A)
        cout << x << " ";

    cout << endl;

    return 0;
}