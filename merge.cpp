#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int start, int mid, int end)
{
    vector<int> temp(end - start + 1);
    int left = start;
    int right = mid + 1;
    int index = 0;
    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            index++;
            left++;
        }
        else
        {
            temp[index] = arr[right];
            index++;
            right++;
        }
    }
    while (left <= mid)
    {
        temp[index] = arr[left];
        index++, left++;
    }
    while (right <= end)
    {
        temp[index] = arr[right];
        index++, right++;
    }
    index = 0;
    while (start <= end)
    {
        arr[start] = temp[index];
        start++;
        index++;
    }
}
void mergesort(int arr[], int start, int end)
{
    if (start == end)

    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
int main()
{
    int arr[] = {6, 3, 1, 2, 8, 9, 10, 7, 3, 10};
    mergesort(arr, 0,9);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
}