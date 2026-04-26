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
void findPreSuc(Node *root, int key)
{
    Node *pre = NULL;
    Node *suc = NULL;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->data == key)
        { // predecessor = rightmost of left subtree
            if (curr->left != NULL)
            {
                Node *temp = curr->left;
                while (temp->right != NULL)
                {
                    temp = temp->right;
                }
                pre = temp;
            }
            if (curr->right != NULL)
            {
                Node *temp = curr->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }

                suc = temp;
            }
            break;
        }
        else if (key < curr->data)
        {
            suc = curr;
            curr = curr->left;
        }
        else
        {
            pre = curr;
            curr = curr->right;
        }
    }
    if (pre)
        cout << "Predecessor: " << pre->data << endl;
    else
        cout << "No Predecessor\n";

    if (suc)
        cout << "Successor: " << suc->data << endl;
    else
        cout << "No Successor\n";
}
int main()
{

    Node *root = NULL;

    root = insert(root, 42);
    root = insert(root, 39);
    root = insert(root, 70);
    root = insert(root, 99);
    root = insert(root, 51);
    root = insert(root, 11);
    root = insert(root, 29);
    root = insert(root, 47);
    root = insert(root, 59);
    root = insert(root, 92);
    root = insert(root, 19);
    root = insert(root, 34);
    root = insert(root, 54);
    root = insert(root, 68);
    root = insert(root, 63);
    root = insert(root, 81);
    root = insert(root, 96);
    root = insert(root, 75);
    root = insert(root, 87);
    root = insert(root, 16);
    root = insert(root, 24);

    int key = 68;

    findPreSuc(root, key);

    return 0;
}