#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to check if the queue is a palindrome
bool isPalindrome(queue<int>& q) {
    stack<int> s;
    int n = q.size();

    // Step 1: Push the first half of the queue into the stack
    for (int i = 0; i < n / 2; ++i) {
        s.push(q.front());
        q.push(q.front());  // Re-enqueue the element to preserve the order
        q.pop();
    }

    // Step 2: Compare the second half of the queue with the stack
    for (int i = 0; i < n / 2; ++i) {
        if (q.front() != s.top()) {
            return false;  // Not a palindrome if mismatch occurs
        }
        q.push(q.front());  // Re-enqueue the element to preserve the order
        q.pop();
        s.pop();
    }

    return true;  // If no mismatch occurs, it's a palindrome
}

int main() {
    // Test case 1: Palindrome
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(2);
    q1.push(1);
    cout << "Is q1 a palindrome? " << (isPalindrome(q1) ? "Yes" : "No") << endl;

    // Test case 2: Not a palindrome
    queue<int> q2;
    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(4);
    q2.push(5);
    cout << "Is q2 a palindrome? " << (isPalindrome(q2) ? "Yes" : "No") << endl;

    // Test case 3: Palindrome
    queue<int> q3;
    q3.push(1);
    q3.push(2);
    q3.push(3);
    q3.push(3);
    q3.push(2);
    q3.push(1);
    cout << "Is q3 a palindrome? " << (isPalindrome(q3) ? "Yes" : "No") << endl;

    return 0;
}
