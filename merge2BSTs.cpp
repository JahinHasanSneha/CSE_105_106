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
void inorder(Node *root, vector<int> &a)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, a);
    a.push_back(root->data);

    inorder(root->right, a);
}
Node *buildBSTFromSorted(vector<int> &temp, int st, int end)
{
    if (st > end)
    {
        return NULL;
    }
    int mid = (st + end) / 2;
    Node *root = new Node(temp[mid]);
    root->left = buildBSTFromSorted(temp, st, mid - 1);
    root->right = buildBSTFromSorted(temp, mid + 1, end);
    return root;
}
Node *merge2BST(Node *root1, Node *root2)
{
    vector<int> arr1, arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);

    vector<int> temp;
    int i = 0;
    int j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            temp.push_back(arr1[i++]);
        }
        else
        {
            temp.push_back(arr2[j++]);
        }
    }
    while (i < arr1.size())
    {
        temp.push_back(arr1[i++]);
    }
    while (j < arr2.size())
    {
        temp.push_back(arr2[j++]);
    }
    return buildBSTFromSorted(temp, 0, temp.size() - 1);
}
int main()
{
    // Build BST 1
    vector<int> a1 = {3, 1, 5};
    Node *root1 = buildBST(a1);

    // Build BST 2
    vector<int> a2 = {4, 2, 6};
    Node *root2 = buildBST(a2);

    cout << "BST1 inorder: ";
    vector<int> t1;
    inorder(root1, t1);
    for (int x : t1)
        cout << x << " ";
    cout << "\n";

    cout << "BST2 inorder: ";
    vector<int> t2;
    inorder(root2, t2);
    for (int x : t2)
        cout << x << " ";
    cout << "\n";

    // Merge
    Node *merged = merge2BST(root1, root2);

    cout << "Merged BST inorder: ";
    vector<int> tm;
    inorder(merged, tm);
    for (int x : tm)
        cout << x << " ";
    cout << "\n";

    return 0;
}
