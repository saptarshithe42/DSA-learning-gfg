#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


// time complexity : O(n)
// iterative
// void traverse_linked_lists(Node* head)
// {
//     Node* curr = head;
//     while (curr != NULL)
//     {
        
//         cout << curr->data << " ";
//         curr = curr->next;
//     }
// }

// recursive
void traverse_linked_lists(Node* head)
{
    if (head == NULL)
        return;
    
    cout << head->data << " ";

    traverse_linked_lists(head->next);
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    traverse_linked_lists(head);

    
    return 0;
}