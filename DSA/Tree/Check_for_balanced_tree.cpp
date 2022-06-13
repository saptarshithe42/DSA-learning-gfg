#include<iostream>
using namespace std;
#include "binary_tree_node.h"

int isBalanced(Node* root)
{
    if(root == NULL)
        return 0;

    int lh = isBalanced(root->left);
    if(lh == -1)
        return -1;
    
    int rh = isBalanced(root->right);
    if(rh == -1)
        return -1;

    if(abs(lh - rh) > 1)
        return -1;

    return max(lh, rh) + 1;
}



int main() {
	
	Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(30);
	root->right->left=new Node(15);
	root->right->right=new Node(20);
	
	cout<<isBalanced(root);
}