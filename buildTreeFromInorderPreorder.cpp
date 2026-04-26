#include <iostream>
#include <string>
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

Node *findNode(Node *root, int val)
{
    while (root != NULL)
    {
        if (val < root->data)
        {
            root = root->left;
        }
        else if (val > root->data)
        {
            root = root->right;
        }
        else
            return root;
    }
    return NULL;
}
int main()
{
    int idx = -1;
    vector<int> preorder = {1, 2, 7, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder, idx);

    int pVal = 2, qVal = 4;

    Node *p = findNode(root, pVal);
    Node *q = findNode(root, qVal);

    if (p == NULL || q == NULL)
    {
        cout << "Either " << pVal << " or " << qVal << " is not in the tree.\n";
        return 0;
    }

    Node *ans = LCA(root, p, q);

    cout << "LCA of " << pVal << " and " << qVal << " is: " << ans->data << "\n";

    return 0;
}