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


// recursive implementation
// time complexity : O(h)
// space complexity : O(h)
// Node* insert (Node* root, int x)
// {
//     if (root == NULL)
//         return (new Node(x));

//     else if(root->key < x)
//         root->right = insert(root->right, x);

//     else if(root->key > x)
//         root->left = insert(root->left, x);

//     return root;
// }

// iterative implementation
// time complexity : O(h)
// space complexity : O(1)
Node *insert(Node *root, int x)
{
    Node *temp = new Node(x);

    Node *parent = NULL, *curr = root;

    while (curr != NULL)
    {
        parent = curr;

        if (curr->key > x)
            curr = curr->left;
        else if (curr->key < x)
            curr = curr->right;
        else
            return root;
    }

    if (parent == NULL)
    {
        return temp;
    }

    if (parent->key > x)
        parent->left = temp;
    else
        parent->right = temp;

    return root;
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->right = new Node(80);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);

    int x = 8;

    preorder(root);

    insert(root, x);

    cout << endl;

    preorder(root);

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