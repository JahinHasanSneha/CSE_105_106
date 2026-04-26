#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define MAX_CAPACITY 1000 // Defines the maximum capacity of the heap

class MinHeap
{
private:
    int heap[MAX_CAPACITY]; // Array to store heap elements
    int size;               // Current number of elements in the heap

    /**
     * Sifts up the node at index i to maintain heap property.
     */
    void siftUp(int i)
    {
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (heap[parent] <= heap[i])
            {
                break;
            }
            else
            {
                swap(heap[parent], heap[i]);
                i = parent;
            }
        }
        /**Write your code here**/
    }

    /**
     * Sifts down the node at index i to maintain heap property.
     */
    void siftDown(int i)
    {

        for (;;)
        {
            int right = 2 * i + 2;
            int left = 2 * i + 1;
            int smallest = i;

            if (left < size && heap[left] < heap[smallest])
            {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest])
            {
                smallest = right;
            }
            if (smallest == i)
            {
                break;
            }
            swap(heap[smallest], heap[i]);
            i = smallest;
        }
        /**Write your code here**/
    }

public:
    // Constructor initializes an empty heap
    MinHeap() : size(0) {}

    /**
     * Inserts a new element x into the heap.
     */
    void insert(int x)
    {
        if (size >= MAX_CAPACITY)
        {
            return;
        }
        heap[size] = x;
        siftUp(size);

        size++;

        /**Write your code here**/
    }

    void mergeHeap(int otherArr[], int otherSize)
    {
        int arr[size + otherSize];
        if (otherSize < 0 || otherSize > MAX_CAPACITY)
        {
            return;
        }
        for (int i = 0; i < size; i++)
        {
            arr[i] = heap[i];
        }
        for (int i = size; i < (size + otherSize); i++)
        {
            arr[i] = otherArr[i - size];
        }
        size = size + otherSize;
        for (int i = (size / 2) - 1; i >= 0; i--)
        {
            for (;;)
            {
                int right = 2 * i + 2;
                int left = 2 * i + 1;
                int smallest = i;
                if (left < size && arr[left] < arr[smallest])
                {
                    smallest = left;
                }
                if (right < size && arr[right] < arr[smallest])
                {
                    smallest = right;
                }
                if (smallest == i)
                {
                    break;
                }
                swap(arr[smallest], arr[i]);
                i = smallest;
            }
        }
        for (int i = 0; i < size; i++)
        {
            heap[i] = arr[i];
        }
    }

    /**
     * Returns the minimum element without removing it.
     */
    int
    findMin()
    {
        if (size == 0)
        {
            return INT_MAX;
        }
        return heap[0];
        /**Write your code here**/
    }

    /**
     * Removes and returns the minimum element from the heap.
     */
    int extractMin()
    {
        if (size == 0)
        {
            return INT_MAX;
        }
        int min = heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (size > 0)
        {
            siftDown(0);
        }
        return min;
        /**Write your code here**/
    }

    /**
     * Returns the number of elements in the heap.
     */
    int getSize()
    {
        return size;

        /**Write your code here**/
    }

    /**
     * Checks if the heap is empty.
     * Returns true if empty, false otherwise.
     */
    bool isEmpty()
    {
        if (size == 0)
        {
            return true;

        } /**Write your code here**/
        return false;
    }

    /**
     * Decreases the value of the element at index i to newValue.
     */
    void decreaseKey(int i, int newValue)
    {
        if (i < 0 || i >= size)
        {
            return;
        }
        if (newValue > heap[i])
        {
            return;
        }
        /**Write your code here**/
        heap[i] = newValue;
        siftUp(i);
    }

    /**
     * Deletes the element at index i.
     */
    void deleteKey(int i)
    {
        if (i < 0 || i >= size)
        {
            return;
        }
        if (i == size - 1)
        {
            size--;
            return;
        }
        heap[i] = heap[size - 1];
        size--;
        int parent = (i - 1) / 2;
        if (i > 0 && heap[parent] > heap[i])
        {
            siftUp(i);
        }
        else
        {
            siftDown(i);
        }
        /**Write your code here**/
    }

    /**
     * Prints the heap's content to the output file.
     * Format: "elem1 elem2 elem3 ..." (space-separated)
     */
    void printHeap(std::ofstream &outfile)
    {
        for (int i = 0; i < size; i++)
        {
            outfile << heap[i];
            if (i + 1 < size)
            {
                outfile << " ";
            }
        }
        outfile << endl;
        /**Write your code here**/
    }

    /**
     * Checks whether the Min Heap property is preserved.
     * Returns true if valid, false otherwise.
     */
    bool isValidMinHeap()
    {
        /**Write your code here**/
        for (int i = 0; i < size; i++)
        {
            int right = 2 * i + 2;
            int left = 2 * i + 1;
            if (left < size && heap[i] > heap[left])
            {
                return false;
            }
            if (right < size && heap[i] > heap[right])
            {
                return false;
            }
        }
        return true;
    }

    /**
     * Builds a heap from an unsorted array using bottom-up heapify.
     */
    void heapify(int arr[], int n)
    {
        if (n < 0 || n > MAX_CAPACITY)
        {
            return;
        }
        for (int i = 0; i < n; i++)
        {
            heap[i] = arr[i];
        }
        size = n;
        for (int i = (size / 2) - 1; i >= 0; i--)
        {
            siftDown(i);
        }

        /**Write your code here**/
    }

    /**
     * Returns all elements in sorted (ascending) order.
     * The original heap should remain UNCHANGED after this operation.
     */
    void heapSort(std::ofstream &outfile)
    {
        int temp[MAX_CAPACITY];
        int tempSize = size;
        for (int i = 0; i < size; i++)
        {
            temp[i] = heap[i];
        }

        while (tempSize > 0)
        {
            outfile << temp[0];
            if (tempSize > 1)
            {
                outfile << " ";
            }
            temp[0] = temp[tempSize - 1];
            tempSize--;
            int i = 0;
            while (1)
            {
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int smallest = i;
                if (left < tempSize && temp[left] < temp[smallest])
                {
                    smallest = left;
                }
                if (right < tempSize && temp[right] < temp[smallest])
                {
                    smallest = right;
                }
                if (smallest == i)
                {
                    break;
                }
                swap(temp[i], temp[smallest]);
                i = smallest;
            }
        }
        outfile << endl;
    }

    /**
     * Replaces the minimum element with a new value x in a single operation.
     * Returns the old minimum value.
     */
    int replaceMin(int x)
    {
        if (size == 0)
        {
            return INT_MAX;
        }

        /**Write your code here**/
        int old = heap[0];
        heap[0] = x;
        siftDown(0);
        return old;
    }
    void kSmallest(int k, std::ofstream &outfile)
    {
        priority_queue<int> p;
        for (int i = 0; i < k; i++)
            p.push(heap[i]);
        for (int i = k; i < size; k++)
        {
            if (p.top() > heap[i])
            {
                p.pop();
                p.push(heap[i]);
            }
        }
        vector<int> smallestElements;
        while (!p.empty())
        {
            smallestElements.push_back(p.top());
            p.pop();
        }
        sort(smallestElements.begin(), smallestElements.end());
        for (int i = 0; i < k; i++)
        {
            outfile << smallestElements[i];
            if (i < k - 1)
            {
                outfile << " "; // Add space between elements
            }
        }
        outfile << endl; // Move to the next line after printing the elements
    }
    void kLargest(int k, std::ofstream &outfile)
    {
        priority_queue<int, vector<int>, greater<int>> p;
        for (int i = 0; i < k; i++)
            p.push(heap[i]);
        for (int i = k; i < size; k++)
        {
            if (p.top() < heap[i])
            {
                p.pop();
                p.push(heap[i]);
            }
        }
        vector<int> largestElements;
        while (!p.empty())
        {
            largestElements.push_back(p.top());
            p.pop();
        }
        sort(largestElements.begin(), largestElements.end());
        for (int i = 0; i < k; i++)
        {
            outfile << largestElements[i];
            if (i < k - 1)
            {
                outfile << " "; // Add space between elements
            }
        }
        outfile << endl; // Move to the next line after printing the elements
    }
};

#endif // MINHEAP_H