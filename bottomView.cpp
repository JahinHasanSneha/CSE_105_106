#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        left = right = NULL;
        data = val;
    }
};
Node *buildTree(vector<int> &preorder, int &idx)
{
    idx++;
    if (idx >= (int)preorder.size())
    {
        return NULL;
    }
    if (preorder[idx] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);
    return root;
}
void bottomView(Node *root)
{
    queue<pair<Node *, int>> q;
    map<int, int> m;
    q.push({root, 0});

    while (q.size() > 0)
    {
        Node *curr = q.front().first;
        int hd = q.front().second;
        q.pop();
        m[hd] = curr->data;
        if (curr->left != NULL)
        {
            q.push({curr->left, hd - 1});
        }
        if (curr->right != NULL)
        {
            q.push({curr->right, hd + 1});
        }
        for (auto it : m)
        {
            cout << it.second << " ";
        }
        cout << endl;
    }
}
int main()
{
    int idx = -1;
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder, idx);
    bottomView(root);
    return 0;
}