#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node *createFromArray(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < n; i++)
    {
        Node *newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = current->next;
    }
    Node *tail = current;
    return head;
}

void printList(Node *head)
{
    Node *cur = head;
    while (cur != nullptr)
    {
        cout << cur->data << " <-> ";
        cur = cur->next;
    }
    cout << "NULL\n";
}

Node *insertAtFront(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

Node *insertAtEnd(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    newNode->prev = cur;
    return head;
}

Node *removeAtFront(Node *head)
{
    if (head == nullptr)
        return nullptr;

    Node *temp = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete temp;
    return head;
}
Node *removeAtLast(Node *head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)

    {
        delete head;
        return nullptr;
    }
    Node *current = head;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = nullptr;
    delete temp;
    return head;
}

Node *getNodeAt(Node *head, int index)
{
    int i = 0;
    while (head != nullptr)
    {
        if (i == index)
            return head;
        head = head->next;
        i++;
    }
    return nullptr;
}

Node *insertAtIdx(Node *head, int index, int val)
{
    if (index == 0)
        return insertAtFront(head, val);

    Node *prev = getNodeAt(head, index - 1);
    if (prev == nullptr)
        return head;

    Node *newNode = new Node(val);
    Node *nextNode = prev->next;

    prev->next = newNode;
    newNode->prev = prev;
    newNode->next = nextNode;

    if (nextNode != nullptr)
        nextNode->prev = newNode;

    return head;
}

Node *removeAtIdx(Node *head, int index)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (index == 0)
    {
        return removeAtFront(head);
    }
    Node *temp = getNodeAt(head, index);
    if (temp == nullptr)
    {
        return head;
    }
    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
    return head;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = 4;

    Node *head = createFromArray(arr, n);
    cout << "Initial list:\n";
    printList(head);

    head = insertAtFront(head, 5);
    cout << "After insert at front:\n";
    printList(head);

    head = insertAtEnd(head, 50);
    cout << "After insert at end:\n";
    printList(head);

    head = insertAtIdx(head, 3, 25);
    cout << "After insert at index 3:\n";
    printList(head);

    head = removeAtIdx(head, 2);
    cout << "After remove at index 2:\n";
    printList(head);

    head = removeAtFront(head);
    cout << "After remove front:\n";
    printList(head);

    head = removeAtLast(head);
    cout << "After remove Last:\n";
    printList(head);
    return 0;
}
