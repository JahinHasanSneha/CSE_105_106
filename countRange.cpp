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
int countR(Node* root,int st,int end)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data<st)
    {
        return countR(root->right,st,end);
    }
    else if(root->data > end)

    {
        return countR(root->left,st,end);
    }
    else{
        return 1+countR(root->left,st,end)+countR(root->right,st,end);
    }
}
int main()
{
    // Build a tree from preorder where -1 means NULL
    vector<int> preorder = {7, 3, 1, -1, -1, 5, -1, -1, 10, 9, -1, -1, 12, -1, -1};
    int idx = -1;
    Node *root = buildTree(preorder, idx);

    int st, end;
    cout << "Enter range (start end): ";
    cin >> st >> end;

    cout << countR(root, st, end) << endl;

    return 0;
}
