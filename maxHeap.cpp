#include <iostream>
using namespace std;
class maxHeap
{
    int *arr;
    int size;
    int total_size;

public:
    maxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }
    // insert into the heap;
    void insert(int value)
    {
        if (size == total_size)
        {
            cout << "heap Overflow" << endl;
            return;
        }
        arr[size] = value;
        int index = size;
        size++;
        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        cout << arr[index] << " is inserted\n";
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void Heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left < size && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }
        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            Heapify(largest);
        }
    }
    void Delete ()
    {
        if (size == 0)
        {
            cout << "Heap UnderFlow" << endl;
            return;
        }
        cout << arr[0] << " deletd from the heap"<<endl;
        arr[0] = arr[size - 1];
        size--;
        if (size == 0)
        {
            return;
        }
        Heapify(0);
    }
};
int main()
{
    maxHeap H1(6);
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);
    H1.print();
    H1.Delete();
    H1.insert(114);
    H1.insert(24);
    H1.insert(1);
    H1.print();
    
}