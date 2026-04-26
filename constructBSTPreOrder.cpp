#include <iostream>
#include <string>
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
Node *findNode(Node *root, int val)
{
    while (root != NULL)
    {
        if (root->data > val)
        {
            root = root->left;
        }
        else if (root->data < val)
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }
    return NULL;
}
Node *constructPre(vector<int> &preOrder, int &i, int bound)
{
    if (i >= preOrder.size() || preOrder[i] > bound)
    {
        return NULL;
    }
    Node *root = new Node(preOrder[i++]);
    root->left = constructPre(preOrder, i, root->data);
    root->right = constructPre(preOrder, i, bound);
    return root;
}
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    int idx = -1;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};


  
   
    int i = 0;
    Node *root = constructPre(preorder, i, INT_MAX);
inOrder(root);
    
    return 0;
}