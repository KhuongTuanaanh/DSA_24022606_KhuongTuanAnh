#include <iostream>
using namespace std;
struct Node{
    int key;
    Node* left;
    Node* right;

    Node(int val) : key(val), left(nullptr), right(nullptr) {
    }
};

class BST{
private:
    Node* root;
    void inorder(Node* node){
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
    void preorder(Node* node){
        if (node == nullptr)
            return;
        cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node* node){
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->key << " ";
    }
    Node* insert(Node* node, int key){
        if (node == nullptr) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        return node;
    }
public:
    BST() : root(nullptr){
    }

    void insert(int key){
        root = insert(root, key);
    }
    void printInorder(){
        cout << "Inorder (Left -> Root -> Right): ";
        inorder(root);
        cout << endl;
    }
    void printPreorder(){
        cout << "Preorder (Root -> Left -> Right): ";
        preorder(root);
        cout << endl;
    }
    void printPostorder(){
        cout << "Postorder (Left -> Right -> Root): ";
        postorder(root);
        cout << endl;
    }
};
