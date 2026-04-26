/*#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int topIndex;
    int capacity;

public:
    // Constructor
    Stack(int size = 100) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Push operation
    void push(int val) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++topIndex] = val;
    }

    // Pop operation
    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        topIndex--;
    }

    // Top operation
    int top() {
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    // Empty check
    bool empty() {
        return topIndex == -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}

*/
#include <iostream>
#include <vector>
using namespace std;
class Stack
{
    vector<int> v;

public:
    void push(int val)
    {
        v.push_back(val);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v[v.size() - 1];
    }
    bool empty()
    {
        return v.size() == 0;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
/*#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Stack
{
    list<int> li;

public:
    void push(int val)
    {
        li.push_front(val);
    }
    void pop()
    {
        li.pop_front();
    }
    int top()
    {
        return li.front();
    }
    bool empty()
    {
        return li.size() == 0;
    }
};



int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}*/