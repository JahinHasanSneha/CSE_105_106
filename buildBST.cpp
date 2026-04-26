#include <iostream>
#include <queue>
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
static int idx = -1;
Node *buildTree(vector<int> preorder)
{
    idx++;
    if (preorder[idx] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
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
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }
        cout << curr->data << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}
void storeLevelOrder(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (q.size() > 0)
    {
        Node *temp = q.front();
        q.pop();
        arr[i++] = temp->data;
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp ->right != NULL)
        {
            q.push(temp->right);
        }
    }
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftH = height(root->left);

    int rightH = height(root->right);
    return (max(leftH, rightH) + 1);
}
int noNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftN = noNodes(root->left);
    int rightN = noNodes(root->right);
    return leftN + rightN + 1;
}
int sum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return (leftSum + rightSum + (root->data));
}
int main()
{
    // Preorder with -1 as NULL marker
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    // Build tree
    Node *root = buildTree(preorder);

    cout << "Preorder Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postOrder(root);
    cout << endl;

    cout << "Level Order Traversal:" << endl;
    levelOrder(root);
    cout << endl;

    // Height
    cout << "Height: " << height(root) << endl;

    // Number of Nodes
    cout << "Total Nodes: " << noNodes(root) << endl;

    // Sum of Nodes
    cout << "Sum of Nodes: " << sum(root) << endl;

    // Store in array (1-based indexing)
    vector<int> arr(100); // large enough size
    storeLevelOrder(root, arr);

    cout << "Stored Level Order Array: ";
    int total = noNodes(root);
    for (int i = 1; i <= total; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
