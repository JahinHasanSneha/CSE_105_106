#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int>& s, int x) {
    // Base case: If the stack is empty, push the element
    if (s.empty()) {
        s.push(x);
    } else {
        // Remove the top element and hold it in a temporary variable
        int temp = s.top();
        s.pop();
        
        // Recursively call insertAtBottom with the remaining stack
        insertAtBottom(s, x);
        
        // Push the removed element back to the stack after the insertion
        s.push(temp);
    }
}

// Function to reverse the stack using recursion
void reverseStack(stack<int>& s) {
    // Base case: If the stack is empty, return
    if (s.empty()) {
        return;
    }
    
    // Pop the top element
    int x = s.top();
    s.pop();
    
    // Recursively reverse the remaining stack
    reverseStack(s);
    
    // Insert the popped element at the bottom of the stack
    insertAtBottom(s, x);
}

int main() {
    stack<int> s;
    
    // Pushing elements to the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    cout << "Original Stack: ";
    stack<int> tempStack = s;  // Temporary stack for displaying
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
    
    // Reversing the stack
    reverseStack(s);
    
    cout << "Reversed Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}