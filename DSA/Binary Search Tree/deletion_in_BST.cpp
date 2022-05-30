#include <iostream>
using namespace std;
struct Node;

void inorder(Node *root);

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

Node* getSuccessor(Node* curr)
{
    curr = curr->right;
    while((curr != NULL) && (curr->left != NULL))
        curr = curr->left;

    return curr;
}


// recursive implementation
// time complexity : O(h)
// space complexity : O(h)

Node* delete_in_BST(Node* root, int x)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->key > x)
    {
        root->left =  delete_in_BST(root->left, x);
    }
    else if (root->key < x)
    {
        root->right = delete_in_BST(root->right, x);
    }
    else
    {
        if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node* succ = getSuccessor(root);
            root->key = succ->key;
            root->right = delete_in_BST(root, succ->key);
        }

    }
        return root;

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

    
    int x = 16;

    inorder(root);
    cout << endl;

    delete_in_BST(root, x);

    inorder(root);



    return 0;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << (root->key) << " ";
        inorder(root->right);
    }
}