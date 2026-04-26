#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int minVal;
stack<int> s;

void push(int val)
{
    if (s.empty())
    {
        s.push(val);
        minVal = val;
    }
    else if (val >= minVal)
    {
        s.push(val);
    }
    else
    {
        s.push(2 * val - minVal);
        minVal = val;
    }
}
void pop()
{
    if (s.empty())
        return;
    int topVal = s.top();
    s.pop();
    if (topVal < minVal)
    {
        minVal = 2 * minVal - topVal;
    }
}
int top()
{
    if (s.empty())
        return -1;
    if (s.top() >= minVal)
        return s.top();
    else
        return minVal;
}
int getMin()
{
    if (s.empty())
    {
        return -1;
    }
    return minVal;
}
int main()
{
    push(5);
    push(3);
    push(7);
    push(2);
    cout << "Min: " << getMin() << endl;
    pop();
    cout << "Min: " << getMin() << endl;
    pop();
    cout << "Top: " << top() << endl;

    cout << "Min: " << getMin() << endl;
    pop();

    return 0;
}