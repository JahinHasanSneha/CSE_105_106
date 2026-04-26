#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse a stack
void reverseStack(stack<int>& s) {
    if (s.empty()) return;  // Base case: If the stack is empty, stop the recursion
    
    int topElement = s.top();  // Get the top element of the stack
    s.pop();  // Pop the top element
    
    reverseStack(s);  // Reverse the remaining stack
    
    // Insert the popped element at the bottom of the reversed stack
    stack<int> tempStack;
    while (!s.empty()) {
        tempStack.push(s.top());
        s.pop();
    }
    s.push(topElement);
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

// Function to reverse a queue
void reverseQueue(queue<int>& q) {
    stack<int> s;
    
    // Step 1: Move all elements from the queue to the stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    
    // Step 2: Move all elements from the stack back to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

// Main function to test the reverse functions
int main() {
    // Test reverseStack
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "Original Stack: ";
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(s);

    cout << "Reversed Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    // Test reverseQueue
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << "Original Queue: ";
    queue<int> tempQueue = q;
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;

    reverseQueue(q);

    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
