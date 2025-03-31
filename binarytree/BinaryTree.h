#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

class BinaryTree 

{
private:
    struct Node 
    {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;


    // Helper methods
    Node* insert(Node* node, int value);
    Node* deleteNode(Node* node, int value);
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    void levelorder(Node* node); 
    int countNodes(Node* node);
    int height(Node* node);


public:
    BinaryTree();
    void insert(int value);
    void deleteValue(int value);
    void inorder();
    void preorder();
    void postorder();
    void levelorder();  
    int countNodes();
    int height();
    bool search(Node* node, int value);
    bool search(int value);
};


#endif // BINARYTREE_H
