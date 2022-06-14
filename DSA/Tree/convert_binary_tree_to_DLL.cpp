#include <iostream>
#include "binary_tree_node.h"
using namespace std;

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->key << " ";
        curr = curr->right;
    }
    cout << endl;
}

Node* prevv = NULL;
Node *convert_BT_to_DLL(Node *root)
{
    if(root == NULL)
        return root;

    Node* head = convert_BT_to_DLL(root->left);
    
    if(prevv == NULL) 
    {
        head = root;
    }
    else
    {
        prevv->right = root;
        root->left = prevv;
    }

    prevv = root;

    convert_BT_to_DLL(root->right);

    return head;
}


int main()
{

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(35);

    Node *head = convert_BT_to_DLL(root);
    printlist(head);
}