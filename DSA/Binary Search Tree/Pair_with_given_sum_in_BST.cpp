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

bool isPairPresent(Node *root, int target, unordered_set<int> &s)
{
    if (root == NULL)
        return false;

    if (isPairPresent(root->left, target, s) == true)
        return true;

    if (s.find(target - root->key) != s.end())
        return true;

    else    
        s.insert(root->key);

    return isPairPresent(root->right, target, s);
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(20);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(30);
    root->right->right->left = new Node(25);

    int sum = 33;
    unordered_set<int> s;
    cout << std::boolalpha;
    cout << isPairPresent(root, sum, s);

    return 0;
}