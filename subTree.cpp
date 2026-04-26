#include <iostream>
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
bool isIdentical(Node *p, Node *q)
{
    if (p == NULL || q == NULL)
    {
        return p == q;
    }
    return p->data == q->data &&
           isIdentical(p->left, q->left) &&
           isIdentical(p->right, q->right);
}
bool isSubTree(Node *root, Node *subRoot)
{
    if (root == NULL || subRoot == NULL)
    {
        return root == subRoot;
    }
    if (root->data == subRoot->data && isIdentical(root, subRoot))
    {
        return true;
    }
    return isSubTree(root->left, subRoot) ||
           isSubTree(root->right, subRoot);
}
int main()
{
    // -------- Build ROOT tree --------
    //          3
    //        /   \
    //       4     5
    //      / \
    //     1   2
    Node *root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(2);

    // -------- Build SUBROOT tree --------
    //       4
    //      / \
    //     1   2
    Node *subRoot = new Node(4);
    subRoot->left = new Node(1);
    subRoot->right = new Node(2);

    // Check subtree
    cout << isSubTree(root, subRoot) << endl; // expected output: 1 (true)

    return 0;
}
