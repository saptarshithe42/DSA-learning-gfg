#include <iostream>
using namespace std;

struct Node;
void preorder(Node *root);

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


void print_nodes_at_distance_k(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << (root->key) << " ";
    }
    print_nodes_at_distance_k(root->left, k - 1);
    print_nodes_at_distance_k(root->right, k - 1);
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

    preorder(root);
    cout << endl;
    int k = 2;
    print_nodes_at_distance_k(root, k);

    // Node* root = new Node(10);
    // root->left = new Node(6);
    // root->right = new Node(8);
    // root->right->right = new Node(7);
    // root->right->right->right = new Node(12);
    // root->right->right->left = new Node(11);

    // preorder(root);
    // cout << endl;
    // int k = 3;
    // print_nodes_at_distance_k(root, k);

    // Node *root = new Node(10);
    // root->left = new Node(20);
    // root->left->left = new Node(30);

    // preorder(root);

    return 0;
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << (root->key) << " ";
        preorder(root->left);
        preorder(root->right);
    }
}