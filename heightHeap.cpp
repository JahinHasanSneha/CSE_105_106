#include <bits/stdc++.h>
using namespace std;

int heapHeight(int n, int arr[]) // arr is unused but kept for signature
{
    int height = 0;
   

    // while (n > 1)
    // {
    //     height++;
    //     n = n / 2;
    // }
    // return height;
   
    if(n==1)
    return 1;
        return floor(log2(n))+1;
    
}

int main()
{
    // Dummy array – not actually used by heapHeight()
    int dummy[] = {0};

    // Test the function with various heap sizes
    cout << "Heap height for n = 1: " << heapHeight(1, dummy) << endl;
    cout << "Heap height for n = 2: " << heapHeight(2, dummy) << endl;
    cout << "Heap height for n = 3: " << heapHeight(3, dummy) << endl;
    cout << "Heap height for n = 4: " << heapHeight(4, dummy) << endl;
    cout << "Heap height for n = 5: " << heapHeight(5, dummy) << endl;
    cout << "Heap height for n = 6: " << heapHeight(6, dummy) << endl;
    cout << "Heap height for n = 7: " << heapHeight(7, dummy) << endl;
    cout << "Heap height for n = 8: " << heapHeight(8, dummy) << endl;

    return 0;
}