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
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    Node *cur = root;
    while (1)
    {
        if (cur->data <= val)
        {
            if (cur->right != NULL)
            {
                cur = cur->right;
            }
            else
            {
                cur->right = new Node(val);
                break;
            }
        }
        else
        {
            if (cur->left != NULL)
            {
                cur = cur->left;
            }
            else
            {
                cur->left = new Node(val);
                break;
            }
        }
    }
    return root;
}
void printLevelOrder(Node *root)
{
    if (root == NULL)
    {
        cout << "empty";
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = (int)q.size();
        while (sz--)
        {
            Node *cur = q.front();
            q.pop();
            cout << cur->data << " ";
            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
        }
        cout << endl;
    }
}
void inorder(Node *root)
{
    if (!root)

    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    int idx = -1;
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder, idx);
    root = insert(root, 5);
    inorder(root);
    cout << endl;
    printLevelOrder(root);

    return 0;
}