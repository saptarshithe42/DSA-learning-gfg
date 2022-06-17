#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void helper_fixBST(Node *root, Node*& prevv, Node*& first, Node*& second)
{
    if(root == NULL)
        return;

    helper_fixBST(root->left, prevv, first, second);

    if(prevv != NULL && root->key < prevv->key)
    {   
        if(first == NULL)
            first = prevv;
        
        second = root;
    }

    prevv = root;

    helper_fixBST(root->right, prevv, first, second);
}
void fixBST(Node* root)
{
    Node *prevv = NULL, *first = NULL, *second = NULL;
    helper_fixBST(root, prevv, first, second);

    swap(first->key, second->key);
}



int main()
{

    Node *root = new Node(18);
    root->left = new Node(60);
    root->right = new Node(70);
    root->left->left = new Node(4);
    root->right->left = new Node(8);
    root->right->right = new Node(80);

    inorder(root);
    cout << endl;
    fixBST(root);
    cout << endl;
    inorder(root);

    return 0;
}