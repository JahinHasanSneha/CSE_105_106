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
Node *getInorderSuccessor(Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

int minDif(Node *root)
{
    Node *prev = NULL;
    if (root == NULL)
    {
        return INT_MAX;
    }
    int ans = INT_MAX;
    ans = min(ans, minDif(root->left));
    if (prev != NULL)
    {
        ans = min(ans, root->data - prev->data);
    }
    prev = root;
    ans = min(ans, minDif(root->right));
    return ans;
}
int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node *root = buildBST(arr);
    inorder(root);
    cout << endl;
    int m = minDif(root);
    cout << m << endl;
    inorder(root);
    cout << endl;

    return 0;
}