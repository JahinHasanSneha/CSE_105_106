#include <iostream>
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
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(const vector<int> &preorder, int &idx)
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
bool isSameTree(Node *p, Node *q)
{
    if (p == NULL || q == NULL)
    {
        return p == q;
    }
    bool isLeftSame = isSameTree(p->left, q->left);
    bool isRightSame = isSameTree(p->right, q->right);
    return isLeftSame && isRightSame && p->data == q->data;
}
void deleteTree(Node *root)

{
    if (!root)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main()
{
    vector<int> preorder1 = {1, 1, -1, -1, 2, -1, -1};
    int idx1 = -1;

    Node *p = buildTree(preorder1, idx1);
    vector<int> preorder2 = {1, 2, -1, -1, 1, -1, -1};
    int idx2 = -1;
    Node *q = buildTree(preorder2, idx2);
    cout << isSameTree(p, q) << endl;
    deleteTree(p);
    deleteTree(q);
}