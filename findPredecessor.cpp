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

// Insert a node in BST
Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// --------- Predecessor Function ----------
Node *getPredecessor(Node *root, int key)
{
    Node *pred = NULL;
    Node *curr = root;

    while (curr != NULL)
    {
        if (key > curr->data)
        {
            pred = curr;
            curr = curr->right;
        }
        else if (key < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            // Node found, check left subtree
            if (curr->left!=NULL)
            {
                curr = curr->left;
                while (curr->right != NULL)
                    curr = curr->right;
                pred = curr;
            }
            break;
        }
    }
    return pred;
}

// --------- Successor Function ----------
Node *getSuccessor(Node *root, int key)
{
    Node *succ = NULL;
    Node *curr = root;

    while (curr != NULL)
    {
        if (key < curr->data)
        {
            succ = curr;
            curr = curr->left;
        }
        else if (key > curr->data)
        {
            curr = curr->right;
        }
        else
        {
            // Node found, check right subtree
            if (curr->right!=NULL)
            {
                curr = curr->right;
                while (curr->left != NULL)
                    curr = curr->left;
                succ = curr;
            }
            break;
        }
    }
    return succ;
}

int main()
{
    // Build BST
    vector<int> vals = {50, 30, 70, 20, 40, 60, 80};
    Node *root = NULL;
    for (int x : vals)
        root = insert(root, x);

    int key = 50;

    Node *pred = getPredecessor(root, key);
    Node *succ = getSuccessor(root, key);

    cout << "Key: " << key << "\n";
    cout << "Predecessor: " << (pred ? to_string(pred->data) : "NULL") << "\n";
    cout << "Successor: " << (succ ? to_string(succ->data) : "NULL") << "\n";

    return 0;
}
