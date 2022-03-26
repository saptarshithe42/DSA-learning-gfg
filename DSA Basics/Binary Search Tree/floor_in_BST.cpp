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


// time complexity : O(h)
// space complexity : O(1)
Node *floor(Node *root, int x)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->key == x)
        {
            return root;
        }

        else if (root->key > x)
            root = root->left;

        else
        {
            res = root;
            root = root->right;
        }
    }
    return res;
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

    int x = 4;


    cout << floor(root, x)->key << endl;

    return 0;
}