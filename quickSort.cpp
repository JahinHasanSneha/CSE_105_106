#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int st, int end)
{
    int idx = st - 1, pivot = arr[end];
    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
} 
void quickSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int pivIdx = partition(arr, st, end);
        quickSort(arr, st, pivIdx - 1);
        quickSort(arr, pivIdx + 1, end);
    }
}
int main()
{
    vector<int> arr = {12, 31, 35, 8, 9, 10};
    quickSort(arr, 0, arr.size() - 1);
    for(int val:arr)
    {
        cout<<val<<" ";
    }
    return 0;
}