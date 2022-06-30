#include <iostream>
#include<cmath>
#include "binary_tree_node.h"
using namespace std;

// naive solution
// time comp : O(n)
// int countNode(Node* root)
// {
//     if(root == NULL)
//         return 0;

//     return 1 + countNode(root->left) + countNode(root->right);
// }


// efficient solution
// time comp : O(logn * logn)
int countNode(Node* root)
{
    int lh = 0, rh =  0;
    Node* curr = root;

    while(curr != NULL)
    {
        lh++;
        curr = curr->left;
    }

    curr = root;

    while(curr != NULL)
    {
        rh++;
        curr = curr->right;
    }

    if(lh == rh)
    {
        return pow(2, lh) - 1;
    }
    else
    {
        return 1 + countNode(root->left) + countNode(root->right);
    }
}


int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << countNode(root);
}