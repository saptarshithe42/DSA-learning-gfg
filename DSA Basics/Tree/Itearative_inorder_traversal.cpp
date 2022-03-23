#include<iostream>
#include<stack>
using namespace std;


struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void iterative_inorder(Node* root)
{
    stack <Node*> s;
    Node* curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();  s.pop();
        cout << (curr->key) << " ";
        curr = curr->right;
    }
}



int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << "\nInorder : ";
    iterative_inorder(root);
    cout << "\n";

    


    return 0;
}