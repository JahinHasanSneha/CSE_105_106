#include <iostream>
using namespace std;

void HeapifyMax(int arr[], int index, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        HeapifyMax(arr, largest, n);
    }
}

void BuildMaxheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        HeapifyMax(arr, i, n);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Corrected heap sort (ascending order using max heap)
void heapSort(int arr[], int n)
{
    BuildMaxheap(arr, n); // Step 1: build max heap
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);  // Move current root to end
        HeapifyMax(arr, 0, i); // Restore heap property on reduced heap
    }
}

int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    print(arr, size);

    // Build max heap and sort
    BuildMaxheap(arr, size);
    cout << "Max heap:       ";
    print(arr, size);

    heapSort(arr, size);
    cout << "Sorted array:   ";
    print(arr, size);

    // Build min heap from sorted array (should remain unchanged)

    return 0;
}