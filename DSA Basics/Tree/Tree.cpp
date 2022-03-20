#include<iostream>
using namespace std;


struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << (root->key) << " ";
        inorder(root->right);
    }
}

void preorder(Node* root)
{
    if (root != NULL)
    {
        cout << (root->key) << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << (root->key) << " ";
    }
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << "\nInorder : ";
    inorder(root);
    cout << "\n";

    cout << "\nPreorder : ";
    preorder(root);
    cout << "\n";

    cout << "\nPostorder : ";
    postorder(root);
    cout << "\n";


    return 0;
}