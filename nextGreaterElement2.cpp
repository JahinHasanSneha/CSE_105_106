#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    vector<int> arr = {1,2,3,4,3};
    stack<int> s;
    vector<int> ans(arr.size(), 0);
    for (int i = 2*arr.size() - 1; i >= 0; i--)
    {
        while (s.size() > 0 && arr[s.top()] <= arr[i%arr.size()])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i%arr.size()] = -1;
        }
        else
        {
            ans[i%arr.size()] = arr[s.top()];
        }
        s.push(i%arr.size());
    }
    for (int val : ans)
        cout << val << " ";
    cout << endl;
    return 0;
}