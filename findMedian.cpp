/**
* Find the median of all keys in the BST
* @return The median key value
* @throws std::runtime_error if BST is empty
*/
virtual Key find_median() = 0;
#include "BST.hpp"
#include "listBST.hpp"
#include <iostream>
#include <fstream>
using namespace std;
int main() {
 ifstream input("in_median.txt");

 if (!input.is_open()) {
 cerr << "Error opening file!" << endl;
 return 1;
 }

 int n;
 input >> n;

 BST<int, string>* bst = new ListBST<int, string>();

 // Read and insert keys
 for (int i = 0; i < n; i++) {
 int key;
 string value;
 input >> key >> value;
 bst->insert(key, value);
 }

 // Find and print median
 try {
 int median = bst->find_median();
 cout << "Median: " << median << endl;
 } catch (const exception& e) {
 cout << "Error: " << e.what() << endl;
 }

 delete bst;

 input.close();

 return 0;
}