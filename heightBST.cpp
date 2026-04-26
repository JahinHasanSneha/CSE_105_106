#include<iostream>
using namespace std;
class Node{
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
int main()
{

}