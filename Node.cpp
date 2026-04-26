#include <iostream>
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
Node *removeHead(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *removeTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *current = head;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    return head;
}

Node *createFromArray(int arr[], int n)
{
    if (n == 0)
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < n; i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

Node *getNodeAt(Node *head, int index)
{
    Node *current = head;
    int currentIndex = 0;
    while (current != nullptr)
    {
        if (currentIndex == index)
        {
            return current;
        }
        current = current->next;
        currentIndex++;
    }
    return nullptr;
}
Node *removeAtIndex(Node *head, int index)
{
    if (head == nullptr)
        return nullptr;
    if (index == 0)
        return removeHead(head);
    Node *current = head;
    for (int i = 0; i < index - 1 && current->next != nullptr; i++)
    {
        current = current->next;
    }
    if (current->next != nullptr)
    {
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
    }
    return head;
}
void updateAtIndex(Node *head, int index, int newVal)
{
    Node *current = head;
    int i = 0;
    while (current != nullptr)
    {
        if (i == index)
        {
            current->data = newVal;
            return;
        }
        current = current->next;
        i++;
    }
}
Node *reverse2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverse2(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
Node *leftRotate(Node *head, int n)
{
    if (head == nullptr || n == 0)
    {
        return head;
    }
    Node *tail = head;
    int len = 1;
    while (tail->next != nullptr)
    {
        tail = tail->next;
        len++;
    }
    n %= len;
    if (n == 0)
        return head;
    Node *current = head;
    for (int i = 1; i < n; i++)
    {
        current = current->next;
    }
    Node *newHead = current->next;
    current->next = nullptr;
    tail->next = head;
    return newHead;
}

Node *rightRotate(Node *head, int n)
{
    if (head == nullptr || n == 0)
    {
        return head;
    }
    Node *tail = head;
    int len = 1;
    while (tail->next != nullptr)
    {
        tail = tail->next;
        len++;
    }
    n %= len;
    if (n == 0)
        return head;
    return leftRotate(head, len - n);
}
int indexOf(Node *head, int val)
{
    Node *current = head;
    int index = 0;
    while (current != nullptr)
    {
        if (current->data == val)
        {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}
Node *getTail(Node *head)
{
    if (head == nullptr)
        return nullptr;
    while (head->next != nullptr)
        head = head->next;
    return head;
}

Node *insertAtFront(Node *head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

Node *insertAtEnd(Node *head, Node *&tail, int val)
{
    if (head == nullptr)
    {
        tail = new Node(val);
        head = tail;
        return head;
    }
    Node *newNode = new Node(val);
    tail->next = newNode;
    tail = newNode;
    return head;
}
Node *insertAtIdx(Node *head, int index, int val)
{
    if (index == 0)
    {
        return insertAtFront(head, val);
    }
    Node *prev = getNodeAt(head, index - 1);
    if (prev != nullptr)
    {
        Node *newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
        return head;
    }
    return head;
}

Node *deleteNode(Node *head, int val)
{
    if (head == nullptr)
        return nullptr;

    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *current = head;
    while (current->next != nullptr && current->next->data != val)
    {
        current = current->next;
    }

    if (current->next != nullptr)
    {
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    return head;
}

Node *reverseLinkedList(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

int main()
{
    int arr[] = {21, 43, 31, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = createFromArray(arr, n);
    Node *tail = getTail(head); // ✅ FIX

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = insertAtFront(head, 99);
    cout << "After inserting 99 at the front: ";
    printLinkedList(head);

    head = insertAtEnd(head, tail, 77);
    cout << "After inserting 77 at the end: ";
    printLinkedList(head);

    head = deleteNode(head, 43);
    cout << "After deleting 43: ";
    printLinkedList(head);

    head = reverseLinkedList(head);
    cout << "After reversing the linked list: ";
    printLinkedList(head);

    return 0;
}
