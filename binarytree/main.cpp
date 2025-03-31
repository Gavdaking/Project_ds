#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() 

    {
    BinaryTree tree;

    // Insert values into the BST
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Inorder Traversal
    tree.inorder();   // Output: 20 30 40 50 60 70 80

    // Search for values

    tree.search(40);  // Output: Found
    
    tree.search(90);  // Output: Not Found

    // Delete a node

    tree.deleteValue(30);  // Make sure method name matches BinaryTree.cpp

    // Inorder traversal after deletion

    tree.inorder();   // Output should reflect deletion

    return 0;
}
