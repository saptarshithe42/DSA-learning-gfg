#include <iostream>
#include<queue>
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

void level_order_traversal(Node* root)
{
    if (root == NULL)
        return;
    
    queue <Node*> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node* curr = q.front();
        q.pop();
        cout << (curr->key) << " ";

        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }  
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

    level_order_traversal(root);
    cout << endl;

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