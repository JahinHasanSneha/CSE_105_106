#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    int half = N / 2;
    stack<int> st;

    // 1) Push first half into stack
    for (int i = 0; i < half; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // 2) Enqueue back stack contents (reversed first half)
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // 3) Move first half (which are reversed) to back -> restores order in front half at front
    for (int i = 0; i < half; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // 4) Push first half again (now in correct order) into stack
    for (int i = 0; i < half; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // 5) Interleave: stack has first half (top is first element), queue has second half
    while (!st.empty())
    {
        q.push(st.top());
        st.pop(); // from first half
        q.push(q.front());
        q.pop(); // from second half
    }

    // Output final queue
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
        if (!q.empty())
            cout << " ";
    }
    cout << "\n";
    return 0;
}
