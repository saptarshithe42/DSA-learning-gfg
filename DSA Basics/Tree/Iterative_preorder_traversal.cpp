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

// time complexity : O(n)
// aux space : O(n)

void iterative_preorder(Node* root)
{
    if (root == NULL)
        return;

    stack <Node*> s;
    s.push(root);

    while (s.empty() == false)
    {
        Node* curr = s.top();
        cout << (curr->key) << " ";
        s.pop();
        if (curr->right != NULL)
            s.push(curr->right);
        if(curr->left != NULL)
            s.push(curr->left);
    }
}



int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << "\nPreorder : ";
    iterative_preorder(root);
    cout << "\n";

    


    return 0;
}