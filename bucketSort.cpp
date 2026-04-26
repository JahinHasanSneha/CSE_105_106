#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<float>& A)
{
    int n = A.size();

    // Create buckets
    vector<vector<float>> buckets(n);

    // Put elements into buckets
    for (int i = 0; i < n; i++)
    {
        int index = n * A[i]; // bucket index
        buckets[index].push_back(A[i]);
    }

    // Sort each bucket
    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // Concatenate all buckets
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (float x : buckets[i])
            A[k++] = x;
    }
}

int main()
{
    vector<float> A = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

    bucketSort(A);

    cout << "Sorted array: ";
    for (float x : A)
        cout << x << " ";

    cout << endl;

    return 0;
}