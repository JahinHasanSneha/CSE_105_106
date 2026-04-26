#include <iostream>
#include <queue>
using namespace std;

int main()
{

    int N;
    cin >> N;

    queue<string> q;
    q.push("1");

    for (int i = 1; i <= N; i++)
    {
        string s = q.front();
        q.pop();

        cout << s << "\n";

        q.push(s + "0");
        q.push(s + "1");
    }

    return 0;
}
