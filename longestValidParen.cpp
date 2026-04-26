#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int longestValidParentheses(const string& s) {
    stack<int> st;
    st.push(-1);          // base index
    int maxLen = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else { // ')'
            st.pop();
            if (st.empty()) {
                st.push(i);   // no matching '(' left, reset base
            } else {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    return maxLen;
}

int main() {
    string s;
    cin >> s;
    cout << longestValidParentheses(s) << endl;
    return 0;
}