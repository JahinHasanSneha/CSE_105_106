#include <iostream>
#include <vector>
using namespace std;

class CircularQ
{
    int *arr;
    int currSize, cap;
    int f = 0, r = -1;

public:
    CircularQ(int size)
    {
        cap = size;
        arr = new int[cap];
        currSize = 0;  // Initialize the current size
    }

    void push(int data)
    {
        if (currSize == cap)
        {
            cout << "CQ is full" << endl;
            return;
        }
        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }

    void pop()
    {
        if (empty())
        {
            cout << "CQ is empty" << endl;
            return;
        }
        f = (f + 1) % cap;
        currSize--;
    }

    bool empty()
    {
        return currSize == 0;
    }

    void print()
    {
        if (empty()) {
            cout << "CQ is empty" << endl;
            return;
        }
        int i = f;
        for (int count = 0; count < currSize; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % cap;
        }
        cout << endl;
    }
};

int main()
{
    CircularQ cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.print();  // This should print 1 2 3
    cq.pop();
    cq.print();  // This should print 2 3 after popping 1
    return 0;
}
