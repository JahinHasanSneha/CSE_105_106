#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    // Constructor to initialize the stack
    MyStack() {}

    // Push an element onto the stack
    void push(int x) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Push the new element into q1
        q1.push(x);
        
        // Move all elements back to q1 from q2
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Pop the element from the stack
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    // Get the top element of the stack
    int top() {
        return q1.front();
    }

    // Check if the stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    // Testing the MyStack class
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << "Top: " << obj->top() << endl;   // Output: 2
    cout << "Pop: " << obj->pop() << endl;   // Output: 2
    cout << "Top: " << obj->top() << endl;   // Output: 1
    cout << "Empty: " << obj->empty() << endl;  // Output: false
    obj->pop();
    cout << "Empty: " << obj->empty() << endl;  // Output: true

    return 0;
}
