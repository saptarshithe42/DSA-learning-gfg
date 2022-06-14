#include <iostream>
#include <deque>
#include <stack>
#include<queue>
#include "binary_tree_node.h"
using namespace std;

// mysol
void printSpiral(Node *root)
{
    if (root == NULL)
        return;
    deque<Node *> q;
    int i = 1;
    q.push_front(root);
    while (q.empty() == false)
    {
        int n = q.size();

        while (n--)
        {
            if (i % 2 != 0)
            {
                Node *curr = q.front();
                q.pop_front();

                cout << curr->key << " ";
                if (curr->left != NULL)
                    q.push_back(curr->left);
                if (curr->right != NULL)
                    q.push_back(curr->right);
            }
            else
            {
                Node *curr = q.back();
                q.pop_back();

                cout << curr->key << " ";
                if (curr->right != NULL)
                    q.push_front(curr->right);
                if (curr->left != NULL)
                    q.push_front(curr->left);
            }
        }

        i++;
    }
}

// gfg sol (method 1)
// void printSpiral(Node *root)
// {
//     if (root == NULL)
//         return;
//     queue<Node *> q;
//     stack<int> s;
//     bool reverse = false;
//     q.push(root);
//     while (q.empty() == false)
//     {
//         int count = q.size();
//         for (int i = 0; i < count; i++)
//         {
//             Node *curr = q.front();
//             q.pop();
//             if (reverse)
//                 s.push(curr->key);
//             else
//                 cout << curr->key << " ";
//             if (curr->left != NULL)
//                 q.push(curr->left);
//             if (curr->right != NULL)
//                 q.push(curr->right);
//         }
//         if (reverse)
//         {
//             while (s.empty() == false)
//             {
//                 cout << s.top() << " ";
//                 s.pop();
//             }
//         }
//         reverse = !reverse;
//     }
// }

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printSpiral(root);
}