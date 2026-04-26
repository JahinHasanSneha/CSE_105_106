#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = nullptr;
    }

    // Push a new element into the queue
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (empty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;  // Update the tail pointer
        }
    }

    // Pop an element from the queue
    void pop()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr)  // If the queue becomes empty, update the tail as well
        {
            tail = nullptr;
        }
    }

    // Get the front element of the queue
    int front()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return -1; // Return an invalid value to indicate an empty queue
        }
        return head->data;
    }

    // Check if the queue is empty
    bool empty()
    {
        return head == nullptr;
    }
};

int main()
{
    Queue q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    
    cout << "Front of the queue: " << q.front() << endl;
    
    q.pop();
    cout << "Front of the queue after pop: " << q.front() << endl;
    
    q.pop();
    q.pop();
    cout << "Queue after popping all elements:" << endl;
    cout << "Front: " << q.front() << endl;

    return 0;
}
