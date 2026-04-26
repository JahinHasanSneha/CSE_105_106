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
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}
Node *buildBST(vector<int> arr)
{
    Node *root = NULL;
    for (int val : arr)
    {
        root = insert(root, val);
    }
    return root;
}
bool search(Node *root, int key)
{
    while (root != NULL)
    {
        if (root->data > key)
        {
            root = root->left;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }
    return false;
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int kthSmallest(Node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    static int prevOrder = 0;
    if (root->left != NULL)
    {
        int leftAns = kthSmallest(root->left, k);
        if (leftAns != -1)
        {
            return leftAns;
        }
    }
    prevOrder = prevOrder + 1;
    if (prevOrder == k)
    {

        return root->data;
    }
    if(root->right!=NULL)
    {
        int rightAns=kthSmallest(root->right,k);
        if(rightAns!=-1)
        {
            return rightAns;
        }
    }
  
    return -1;
}
int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node *root = buildBST(arr);
    inorder(root);
    cout << endl;
    int m = kthSmallest(root,5);
    cout << m << endl;
    inorder(root);
    cout << endl;

    return 0;
}