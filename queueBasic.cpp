#include <iostream>
#include <vector>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(4);
    dq.pop_back();
    cout << dq.front() << " " << dq.back() << endl;
    return 0;
}
