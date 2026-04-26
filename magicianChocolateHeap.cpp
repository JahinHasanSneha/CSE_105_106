#include <bits/stdc++.h>
using namespace std;
int nchoc(int A, vector<int> &B)
{
    priority_queue<int> p;
    for (int i = 0; i < B.size(); i++)
    {
        p.push(B[i]);
    }
    int maxChoc = 0;
    while (A && p.size() > 0)
    {
        maxChoc = p.top() + maxChoc;
        if (p.top() / 2)
            p.push(p.top() / 2);
        p.pop();
        A--;
    }
    return maxChoc;
}
int main() {
    // Test case 1
    vector<int> bags1 = {2, 4, 6, 8, 10};
    int minutes1 = 5;
    cout << "Maximum chocolates in " << minutes1 << " minutes: " 
         << nchoc(minutes1, bags1) << endl;

    // Test case 2
    vector<int> bags2 = {1, 2, 3, 4};
    int minutes2 = 3;
    cout << "Maximum chocolates in " << minutes2 << " minutes: " 
         << nchoc(minutes2, bags2) << endl;

    // Test case 3 (A larger than number of distinct bags, but we keep taking halves)
    vector<int> bags3 = {5, 5, 5};
    int minutes3 = 10;
    cout << "Maximum chocolates in " << minutes3 << " minutes: " 
         << nchoc(minutes3, bags3) << endl;

    return 0;
}