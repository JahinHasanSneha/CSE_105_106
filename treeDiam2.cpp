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
int ans = 0;
int height(Node *root)
{if(root==NULL)
    {
        return 0;
    }
    int leftH = height(root->left);
    int rightH = height(root->right);
    ans = max(ans, leftH + rightH);
    return max(leftH, rightH) + 1;
}
int diameterOfBinaryTree(Node *root)

{
    height(root);
    return ans;
}
int main()
{
    // Example tree (preorder with -1 as NULL):
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    //
    // Preorder with nulls: 1,2,4,-1,-1,5,-1,-1,3,-1,-1
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};

    int idx = -1;
    Node *root = buildTree(preorder, idx);

    cout << "Height: " << height(root) << endl;
    cout << "Diameter: " << diameterOfBinaryTree(root) << endl;

    return 0;
}
