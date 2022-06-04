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

void iterative_preorder(Node* root)
{
    if(root == NULL)
        return;

    stack<Node*> s;
    s.push(root);
    while(s.empty() == false)
    {
        Node* curr = s.top();
        s.pop();
        cout << curr->key << " ";

        if(curr->right != NULL)
            s.push(curr->right);

        if(curr->left != NULL)
            s.push(curr->left);
    }
}


void iterative_inorder(Node* root)
{
    if(root == NULL)
        return;

    stack<Node*> s;

    Node* curr = root;

    while(curr != NULL || s.empty() == false)
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        cout << curr->key << " ";
        curr = curr->right;
    }

}

// using two stacks
void iterative_postorder(Node* root)
{
    if(root == NULL)
        return;

    stack<Node*> s1, s2;

    s1.push(root);

    while(s1.empty() == false)
    {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if(curr->left != NULL)
            s1.push(curr->left);
        
        if(curr->right != NULL)
            s1.push(curr->right);
    }

    while(s2.empty() == false)
    {
        cout << s2.top()->key << " ";
        s2.pop();
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

    cout << "\nInorder : ";
    iterative_inorder(root);
    cout << "\n";

    cout << "\nPostorder : ";
    iterative_postorder(root);
    cout << "\n";
    


    return 0;
}

