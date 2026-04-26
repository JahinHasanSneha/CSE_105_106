#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;  // Stack to store elements for queue
    stack<int> s2;  // Temporary stack to reverse order during pop

    // Constructor
    MyQueue() {}

    // Push an element to the back of the queue
    void push(int x) {
        s1.push(x);  // Simply push the element to s1
    }

    // Pop an element from the front of the queue
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());  // Transfer all elements from s1 to s2
                s1.pop();
            }
        }
        int ans = s2.top();  // The front element is now at the top of s2
        s2.pop();
        return ans;
    }

    // Get the front element of the queue
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());  // Transfer all elements from s1 to s2
                s1.pop();
            }
        }
        return s2.top();  // Return the top of s2 which represents the front element
    }

    // Check if the queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

// Testing the MyQueue class
int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    cout << "Peek: " << obj->peek() << endl;   // Output: 1
    cout << "Pop: " << obj->pop() << endl;     // Output: 1
    cout << "Peek: " << obj->peek() << endl;   // Output: 2
    cout << "Empty: " << obj->empty() << endl; // Output: false
    obj->pop();
    cout << "Empty: " << obj->empty() << endl; // Output: true

    return 0;
}
