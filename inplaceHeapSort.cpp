#include <iostream>
using namespace std;

void siftDown(int arr[], int n, int i)
{
    while (true)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < n && arr[left] < arr[smallest])
            smallest = left;

        if (right < n && arr[right] < arr[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(arr[i], arr[smallest]);
        i = smallest;
    }
}

void inplaceSort(int arr[], int n)
{
    // Build Min Heap
    for (int i = n/2 - 1; i >= 0; i--)
        siftDown(arr, n, i);

    // Heap sort
    for (int end = n - 1; end > 0; end--)
    {
        swap(arr[0], arr[end]);
        siftDown(arr, end, 0);
    }
}//descending


int main()
{
    int arr[] = {50, 30, 20, 15, 10, 40, 25, 35};
    int n = sizeof(arr) / sizeof(arr[0]);

    inplaceSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}