#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> expr = {"(", "1", "+", "(", "(", "2", "+", "3", ")", "*", "(", "4", "*", "5", ")", ")", ")"};
    stack<string> ops;
    stack<int> vals;
    for (string token : expr)
    {
        if (token == "(")
        {
            continue;
        }

        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            ops.push(token);
        }
        else if (token == ")")
        {
            string op = ops.top();
            ops.pop();
            int v2 = vals.top();
            vals.pop();
            int v1 = vals.top();
            vals.pop();
            int result = 0;
            if (op == "+")
            {
                result = v1 + v2;
            }
            else if (op == "-")
            {
                result = v1 - v2;
            }
            else if (op == "*")
            {
                result = v1 * v2;
            }
            else if (op == "/")
            {
                result = v1 / v2;
            }
            vals.push(result);
        }
        else
        {
            vals.push(stoi(token));
        }
    }
    cout << "result " << vals.top() << endl;
}