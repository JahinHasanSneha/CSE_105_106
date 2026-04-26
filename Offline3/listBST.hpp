#ifndef LISTBST_H
#define LISTBST_H

#include "BST.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * Binary Search Tree implementation using linked list structure
 *
 * @tparam Key - The type of keys stored in the BST
 * @tparam Value - The type of values associated with keys
 */
template <typename Key, typename Value>
class ListBST : public BST<Key, Value>
{
private:
    /**
     * Node class for the binary search tree
     */
    class Node
    {
    public:
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node *root;
    size_t node_count;

    // TODO: Implement private helper functions as needed
    // Start your private helper functions here
    Node *findNode(Node *n, const Key &key) const
    {
        while (n != NULL)
        {
            if (key < n->key)
            {
                n = n->left;
            }
            else if (key > n->key)
            {
                n = n->right;
            }
            else
                return n;
        }
        return NULL;
    }
    template <typename Func>
    void inorderVisit(Node *n, Func &visit) const
    {
        if (!n)
            return;
        inorderVisit(n->left, visit);
        visit(n->key, n->value);
        inorderVisit(n->right, visit);
    }
    void destroy(Node *n)
    {
        if (n == NULL)
        {
            return;
        }
        destroy(n->right);
        destroy(n->left);
        delete n;
    }
    bool valid(Node* n,bool hasMin,Key minV,bool hasMax,KeymaxV) const{
        if(n==NULL)
        {
            return true;
        }
        if(hasMin && n->key<=minV)

        {
            return false;
        }
        if(hasMax && n->key>=maxV)

        {
            return false;
        }
return valid(n->left,hasMin,minV,true)
    }
    void printDefault(Node *n) const
    {
        if (n == NULL)
        {
            return;
        }
        cout << "(" << n->key << ":" << n->value;
        bool hasLeft = (n->left != NULL);
        bool hasRight = (n->right != NULL);
        if (hasLeft || hasRight)
        {
            cout << " ";
            if (hasLeft)
            {
                printDefault(n->left);
            }
            else if (hasRight)
            {
                cout << "()";
            }
            if (hasRight)
            {
                cout << " ";
                printDefault(n->right);
            }
        }
        cout << ")";
    }

    Node *minNode(Node *n) const
    {
        if (n == NULL)
        {
            return NULL;
        }

        while (n->left)
        {
            n = n->left;
        }
        return n;
    }
    Node *maxNode(Node *n) const
    {
        if (n == NULL)
        {
            return NULL;
        }

        while (n->right)
        {
            n = n->right;
        }
        return n;
    }

    bool medianNode(Node *n, int &count, int t1, int t2, Key &a, Key &b) const
    {
        if (!n)
        {
            return false;
        }
        if (medianNode(n->left, count, t1, t2, a, b))
        {
            return true;
        }
        count++;
        if (count == t1)
        {
            a = n->key;
        }
        if (count == t2)
        {
            b = n->key;
            return true;
        }
        return medianNode(n->right, count, t1, t2, a, b);
    }
    void kthVisit(Node *n, int &count, int k, Key &ans, bool &found)
    {if (n == NULL || found)
        return;
        kthVisit(n->left, count, k, ans, found);
        if (found)
        {
            return;
        }
        count++;
        if (count == k)
        {
            ans = n->key;
            found = true;
            return;
        }
        kthVisit(n->right, count, k, ans, found);
        return ans;
    }
    int countRange(Node *n, const Key &l, const Key &r) const
    {
        if (n == NULL)
        {
            return 0;
        }
        if (n->key < l)
            return countRange(n->right, l, r);
        if (n->key > r)
            return countRange(n->left, l, r);
        return countRange(n->right, l, r) + 1 + countRange(n->left, l, r);
    }
    Node *removeKey(Node *n, const Key &key, bool &removed) // delete key
    {
        if (n == NULL)
        {
            return NULL;
        }
        if (key < n->key)
        {
            n->left = removeKey(n->left, key, removed);
        }
        else if (key > n->key)
        {
            n->right = removeKey(n->right, key, removed);
        }
        else

        {
            removed = true;            // found
            if (!n->left && !n->right) // No child
            {
                delete n;
                return NULL;
            }
            // 1 child
            if (n->left == NULL)
            {
                Node *temp = n->right;
                delete n;
                return temp;
            }
            if (n->right == NULL)
            {
                Node *temp = n->left;
                delete n;
                return temp;
            }
            // 2 children
            Node *next = minNode(n->right);
            n->key = next->key;
            n->value = next->value;
            bool removed2 = false;
            n->right = removeKey(n->right, next->key, removed2);
        }
        return n;
    }
    void printInorder(Node *n) const
    {
        if (n == NULL)
        {
            return;
        }
        printInorder(n->left);
        cout << "(" << n->key << ":" << n->value << ")";
        cout << " ";
        printInorder(n->right);
    }
    void printPreorder(Node *n) const
    {
        if (n == NULL)
        {
            return;
        }
        cout << "(" << n->key << ":" << n->value << ")";
        cout << " ";
        printPreorder(n->left);

        printPreorder(n->right);
    }
    void printPostorder(Node *n) const
    {
        if (n == NULL)
        {
            return;
        }

        printPostorder(n->left);

        printPostorder(n->right);
        cout << "(" << n->key << ":" << n->value << ")";
        cout << " ";
    }

    // End your private helper functions here

public:
    /**
     * Constructor
     */
    ListBST() : root(nullptr), node_count(0) {}

    /**
     * Destructor
     */
    ~ListBST()
    {
        clear();
        // TODO: Implement destructor to free memory
    }

    /**
     * Insert a key-value pair into the BST
     */
    bool insert(Key key, Value value) override
    {
        // TODO: Implement insertion logic
        if (root == NULL)
        {
            root = new Node(key, value);
            node_count++;
            return true;
        }
        Node *cur = root;
        while (1)
        {
            if (key > cur->key)
            {
                if (cur->right != NULL)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = new Node(key, value);
                    node_count++;
                    return true;
                }
            }
            else if (key < cur->key)
            {
                if (cur->left != NULL)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = new Node(key, value);
                    node_count++;
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }

    /**
     * Remove a key-value pair from the BST
     */
    bool remove(Key key) override
    {
        bool removed = false;

        // TODO: Implement removal logic
        root = removeKey(root, key, removed);
        if (removed)
        {
            node_count--;
        }
        return removed;
    }
    /**
     * Find the median of all keys in the BST
     * @return The median key value
     * @throws std::runtime_error if BST is empty
     */
    Key find_median() override
    {
        if (this->empty())
        {
            throw std::runtime_error("Empty");
        }
        int n = (int)this->size();
        int t1, t2;
        if (n % 2 == 1)
        {

            t1 = t2 = (n + 1) / 2;
        }
        else
        {
            t1 = n / 2;
            t2 = t1 + 1;
        }
        int count = 0;
        Key a{};
        Key b{};
        medianNode(root, count, t1, t2, a, b);
        return (a + b) / 2;
    }
    /**
     * Find if a key exists in the BST
     */
    bool find(Key key) const override
    {
        // TODO: Implement find logic
        return findNode(root, key) != NULL;
    }

    /**
     * Find a value associated with a given key
     */
    Value get(Key key) const override
    {
        // TODO: Implement get logic
        Node *n = findNode(root, key);
        if (n == NULL)
        {
            throw std::out_of_range("Key not found in BST.");
        }
        return n->value;
    }

    /**
     * Update the value associated with a given key
     */
    void update(Key key, Value value) override
    {
        // TODO: Implement update logic
        Node *n = findNode(root, key);
        if (n == NULL)
        {
            throw std::out_of_range("Key not found in BST.");
        }
        n->value = value;
    }

    /**
     * Clear all elements from the BST
     */
    void clear() override
    {
        destroy(root);
        root = NULL;
        node_count = 0;
        // TODO: Implement clear logic
    }

    /**
     * Get the number of keys in the BST
     */
    size_t size() const override
    {
        return node_count;
        // TODO: Implement size logic
    }

    /**
     * Check if the BST is empty
     */
    bool empty() const override
    {
        return node_count == 0;
        // TODO: Implement empty check logic
    }

    /**
     * Find the minimum key in the BST
     */
    Key find_min() const override
    {
        return minNode(root)->key;

        // TODO: Implement find_min logic
    }
    /**
     * Find the Lowest Common Ancestor of two keys in the BST
     * @param key1 - First key
     * @param key2 - Second key
     * @return The key of the LCA node
     * Assumption: Both keys are guaranteed to exist in the BST
     */
    Key find_lca(Key key1, Key key2) override
    {
        if (this->empty())
        {
            throw std::runtime_error("Empty");
        }
        Node *cur = root;
        while (cur != NULL)
        {
            if (key1 < cur->key && key2 < cur->key)
            {
                cur = cur->left;
            }
            else if (key1 > cur->key && key2 > cur->key)
            {
                cur = cur->right;
            }
            else
            {
                return cur->key;
            }
        }
    }
    Key find_max() const override
    {
        return maxNode(root)->key;
        // TODO: Implement find_max logic
    }

    /**
     * Print the BST using specified traversal method
     */
    Key kthSmall(int k) const override
    {
        if (root == NULL)
        {
            throw runtime_error("invalid k");
        }
        int count = 0;
        bool found = false;
        Key ans{};
        kthVisit(root, count, k, ans, found);
    }
    void print(char traversal_type = 'D') const override
    {
        if (!root)
        {
            cout << "(empty)" << endl;
            return;
        }
        // TODO: Implement print logic
        if (traversal_type == 'D')
        {
            printDefault(root);
            cout << endl;
        }
        else if (traversal_type == 'I')
        {
            printInorder(root);
            cout << endl;
        }
        else if (traversal_type == 'P')
        {
            printPreorder(root);
            cout << endl;
        }
        else if (traversal_type == 'O')
        {
            printPostorder(root);
            cout << endl;
        }
        else
        {
            printDefault(root);
            cout << endl;
        }
    }

    // traverse items in sorted order
    template <typename Func>
    void inorder_traverse(Func visit) const
    {
        inorderVisit(root, visit);
    }
};

#endif // LISTBST_H