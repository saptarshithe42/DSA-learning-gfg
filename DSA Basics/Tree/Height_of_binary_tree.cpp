#include<iostream>
using namespace std;

struct Node;
void preorder(Node* root);

struct Node
{
    int key;
    Node* left, *right;

    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// mysol (similar to gfg sol)

// time complexity : O(n)  (n is no. of nodes)
// Aux space : O(h)  (h is height of binary tree)
int height_of_binary_tree(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lcount = height_of_binary_tree(root->left);
    int rcount = height_of_binary_tree(root->right);
    int res = max(lcount, rcount);

    return (res + 1);
}

int main()
{
    // Node* root = NULL;
    // Node* root = new Node(10);
    // root->left = new Node(8);
    // root->right = new Node(30);
    // root->right->left = new Node(40);
    // root->right->right = new Node(50);
    // root->right->right->left = new Node(70);

    // preorder(root);
    // cout << "\nheight : " << height_of_binary_tree(root) << endl;


    // Node* root = new Node(30);
    // root->left = new Node(40);
    // root->right = new Node(60);
    // root->left->left = new Node(70);
    // root->left->left->left = new Node(80);

    // preorder(root);
    // cout << "\nheight : " << height_of_binary_tree(root) << endl;


    Node* root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(30);

    preorder(root);
    cout << "\nheight : " << height_of_binary_tree(root) << endl;


    


    return 0;
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