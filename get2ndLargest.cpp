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
int get2ndLargest(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    Node *cur = root;
    Node *parent = NULL;
    while (cur->right != NULL)
    {
        parent = cur;
        cur = cur->right;
    }
    if (cur->left != NULL)
    {
        Node *t = cur->left;
        while (t->right != NULL)
        {
            t = t->right;
        }
        return t->data;
    }
    if (parent != NULL)
    {
        return parent->data;
    }
    return -1;
}
int main()
{
    // Example tree (preorder with -1 = NULL)
    // You can change this input any time
    vector<int> preorder = {5, 3, 0, -1, -1, -1, 9, 7, -1, -1, -1};
    int idx = -1;

    Node *root = buildTree(preorder, idx);

    int ans = get2ndLargest(root);
    cout << ans << endl;

    return 0;
}