#include "BST.hpp"
#include "listBST.hpp"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream input("in_median.txt");

    if (!input.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int n;
    input >> n;

    BST<int, string> *bst = new ListBST<int, string>();

    // Read and insert keys
    for (int i = 0; i < n; i++)
    {
        int key;
        string value;
        input >> key >> value;
        bst->insert(key, value);
    }
    // Read number of queries
    int q;
    input >> q;

    // Process each query
    for (int i = 0; i < q; i++)
    {
        int key1, key2;
        input >> key1 >> key2;

        int lca = bst->find_lca(key1, key2);
        cout << "LCA(" << key1 << ", " << key2 << ") = " << lca << endl;
    }

    delete bst;

    input.close();

    return 0;
}