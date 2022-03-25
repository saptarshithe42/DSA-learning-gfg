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

// recursive implementation
// time complexity : O(h)
// space complexity : O(h)
// bool search(Node* root, int x)
// {
//     if (root == NULL)
//         return false;

//     else if (root->key == x)
//         return true;

//     else if (root->key > x)
//         return (search(root->left, x));

//     else
//         return search(root->right, x);
// }

// iterative implementation
// time complexity : O(h)
// space complexity : O(1)
bool search(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->key == x) 
            return true;

        else if (root->key > x) 
            root = root->left;

        else 
            root = root->right;
    }
    return false;
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

    int x = 80;

    cout << std::boolalpha;

    cout << search(root, x) << endl;

    return 0;
}