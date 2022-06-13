#include <bits/stdc++.h>
#include "binary_tree_node.h"
using namespace std;



// method 2 (iterative)
void leftView(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();

        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if(i == 0)
                cout << curr->key << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}

int main()
{

/* 
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
 */

/* 
    Node *root = new Node(10);
    root->left = new Node(50);
    root->right = new Node(60);
    root->right->right = new Node(20);
    root->right->left = new Node(70);
    root->right->left->right = new Node(8);
 */

    Node *root = new Node(30);
    root->right = new Node(50);
    root->right->left = new Node(60);
    root->right->left->right = new Node(10);


    leftView(root);
}