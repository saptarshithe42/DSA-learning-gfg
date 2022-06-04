struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int k)
    {
        key = k;
        left = right = nullptr;
    }
};