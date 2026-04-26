#include "queue.h"
#include <iostream>
using namespace std;
// Constructor implementation
ArrayQueue::ArrayQueue(int initial_capacity)
{
    // TODO: Initialize data members (data, capacity, front_idx, rear_idx)
    capacity = initial_capacity;
    front_idx = -1;
    rear_idx = -1;
    data = new int[capacity];
    // current_size = 0;
    //  TODO: Allocate memory for the array with the specified initial capacity
}

// Destructor implementation
ArrayQueue::~ArrayQueue()
{
    delete[] data;
    data = NULL;

    // TODO: Free the dynamically allocated memory for the array
}

// Enqueue implementation (add an item to the rear of the queue)
void ArrayQueue::enqueue(int item)
{
    // TODO: Check if the array is full
    if (size() == capacity)
    {
        resize(capacity * 2);
    }
    rear_idx = (rear_idx + 1) % capacity;

    data[rear_idx] = item;
    // TODO: If full, resize the array to double its current capacity
    // TODO: Add the new element to the rear of the queue
}

// Dequeue implementation (remove an item from the front of the queue)
int ArrayQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    if (empty())
    {
        cout << "No" << endl;
        return -1;
    }
    int value = data[front_idx];
    if (front_idx == rear_idx)
    {
        front_idx = rear_idx = -1;
    }
    // TODO: Update front index
    // TODO: If the array is less than 25% full, resize it to half its current capacity (but not less than 2)
    else
    {
        front_idx = (front_idx + 1) % capacity;
    }
    if (capacity >= 4 && size() * 4 < capacity)
    {
        resize(capacity / 2);
    }
    // TODO: Return the dequeued element
    return value;
}

// Clear implementation
void ArrayQueue::clear()
{
    front_idx = -1;
    rear_idx = -1;
    capacity = 2;
    resize(capacity);
    // TODO: Reset the queue to be empty (reset capacity, front_idx, rear_idx, data)
}

// Size implementation
int ArrayQueue::size() const
{
    if (front_idx == -1)
    {
        return 0;
    }
    return front_idx <= rear_idx ? rear_idx - front_idx + 1 : rear_idx + capacity - front_idx + 1;

    // TODO: Return the number of elements currently in the queue
}

// Front implementation
int ArrayQueue::front() const
{
    if (empty())
    {
        cout << "nO";
        return -1;
    }
    return data[front_idx];
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the front of the queue without removing it
}

// Back implementation (get the element at the back of the queue)
int ArrayQueue::back() const
{
    if (empty())
    {
        cout << "nO";
        return -1;
    }
    return data[rear_idx];
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the back of the queue without removing it
}

// Empty implementation
bool ArrayQueue::empty() const
{
    return size() == 0;
    // TODO: Return whether the queue is empty
}

// Print implementation
string ArrayQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
}

// Resize implementation
void ArrayQueue::resize(int new_capacity)
{int* new_array=new int[new_capacity];
    int count=size();
    for(int i=0;i<count;i++)
    {
        int idx=(front_idx+i)%capacity;
        new_array[i]=data[idx];
    }
    // TODO: Create a new array with the new capacity
    // TODO: Copy elements from the old array to the new array
    // TODO: Delete the old array
    delete[] data;
    data=new_array;
    front_idx=count==0?-1:0;
    rear_idx=count-1;
    capacity=new_capacity;
        // TODO: Update the data pointer and capacity
    // TODO: Update front and rear indices
}

int ArrayQueue::getCapacity() const
{return capacity;
    // TODO: Return the current capacity of the queue
}