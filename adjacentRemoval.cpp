#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<char> s;
    char ch;
    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        if (!s.empty() && s.top() == ch)
        {
            s.pop();
        }
        else
        {
            s.push(ch);
        }
    }
    string ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}