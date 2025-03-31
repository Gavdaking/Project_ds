#include "BinaryTree.h"
#include <queue>  

// Constructor
BinaryTree::BinaryTree() 
    {
    root = nullptr;
}


BinaryTree::Node* BinaryTree::insert(Node* node, int value)
    
    {
    if (node == nullptr) return new Node(value);
    if (value < node->data) node->left = insert(node->left, value);
    else if (value > node->data) node->right = insert(node->right, value);
    return node;
}

void BinaryTree::insert(int value) 
{
    root = insert(root, value);
}


bool BinaryTree::search(Node* node, int value) 
{
    if (node == nullptr) {
        cout << "Not Found" << endl;
        return false;
    }
    if (node->data == value) {
        cout << "Found" << endl;
        return true;
    }
    return search(value < node->data ? node->left : node->right, value);
}

bool BinaryTree::search(int value) {
    return search(root, value);
}

BinaryTree::Node* BinaryTree::deleteNode(Node* node, int value)
 {
    if (node == nullptr) return node;

    if (value < node->data) node->left = deleteNode(node->left, value);
    else if (value > node->data) node->right = deleteNode(node->right, value);
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = node->right;
        while (temp->left != nullptr) temp = temp->left;
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

void BinaryTree::deleteValue(int value) 

{
    root = deleteNode(root, value);
}

// Inorder traversal (recursive)
void BinaryTree::inorder(Node* node) 
{
    if (node) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void BinaryTree::inorder() 
{
    inorder(root);
    cout << endl;
}

// Preorder traversal (recursive)
void BinaryTree::preorder(Node* node) 
{
    if (node) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void BinaryTree::preorder() {
    preorder(root);
    cout << endl;
}

// Postorder traversal (recursive)
void BinaryTree::postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

void BinaryTree::postorder() 
{
    postorder(root);
    cout << endl;
}

// 🔹 Level-order traversal 
void BinaryTree::levelorder() 
{
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

// Count nodes (recursive)
int BinaryTree::countNodes(Node* node) 
{
    return node ? 1 + countNodes(node->left) + countNodes(node->right) : 0;
}

int BinaryTree::countNodes()

 {
    return countNodes(root);
}

// Find height (recursive)
int BinaryTree::height(Node* node) 

{
    return node ? 1 + max(height(node->left), height(node->right)) : -1;
}

int BinaryTree::height() {
    return height(root);
}
