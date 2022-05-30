#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;

    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// time complexity : O(n)  (n is no. of nodes)
// Aux space : O(h)  (h is height of binary tree)

int maximum_in_binary_tree(Node* root)
{
    if (root == NULL)
        return INT_MIN;
    
    return (max(root->key, max(maximum_in_binary_tree(root->left), maximum_in_binary_tree(root->right))));
}

int main()
{

    // Node* root = NULL;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(70);

    // cout << size_of_binary_tree(root) <<endl;


    // Node* root = new Node(10);
    // root->left = new Node(6);
    // root->right = new Node(8);
    // root->right->right = new Node(7);
    // root->right->right->right = new Node(12);
    // root->right->right->left = new Node(11);

    // cout << size_of_binary_tree(root) <<endl;

    // preorder(root);
    // cout << endl;
    // int k = 3;
    // print_nodes_at_distance_k(root, k);

    // Node *root = new Node(10);
    // root->left = new Node(20);
    // root->left->left = new Node(30);
    cout << maximum_in_binary_tree(root) <<endl;

    // preorder(root);

    return 0;
}