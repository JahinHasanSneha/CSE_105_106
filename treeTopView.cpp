#include <iostream>
#include <queue>
#include <map>
#include <stack>

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

// void topView(Node *root)
// {
//     queue<pair<Node *, int>> q;
//     map<int, int> m;
//     q.push({root, 0});
//     while (q.size() > 0)
//     {
//         Node *curr = q.front().first;
//         int currHD = q.front().second;
//         q.pop();
//         if (m.find(currHD) == m.end())
//         {
//             m[currHD] = curr->data;
//         }
//         if (curr->left != NULL)
//         {
//             q.push({curr->left, currHD - 1});
//         }
//         if (curr->right != NULL)
//         {
//             q.push({curr->right, currHD + 1});
//         }
//     }
//     for (auto it : m)
//     {
//         cout << it.second << " ";
//     }
//     cout << endl;
// }
void topView(Node *root)
{
    queue<pair<Node *, int>> q;
    map<int, int> m;

    q.push({root, 0});
    while (q.size() > 0)
    {
        Node *curr = q.front().first;
        int currHD = q.front().second;
        q.pop();
        if (m.find(currHD) == m.end())
        {
            m[currHD] = curr->data;
        }
        if (curr->left != NULL)
        {
            q.push({curr->left, currHD - 1});
        }
        if (curr->right != NULL)
        {
            q.push({curr->right, currHD + 1});
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
    topView(root);
    return 0;
}