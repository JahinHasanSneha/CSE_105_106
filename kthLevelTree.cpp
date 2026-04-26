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
void kthLevel(Node *root, int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==1)
    {cout<<root->data;
        return ;
    }
    kthLevel(root->left,k-1);
    kthLevel(root->right,k-1);

}
int main()
{
    int idx = -1;
    vector<int> preorder = {1, 2,7, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder, idx);
    kthLevel(root,2);
    return 0;
}