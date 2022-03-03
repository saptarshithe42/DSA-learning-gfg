#include<iostream>
#include<vector>
using namespace std;


struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// method 1
// Node* reverseLL(Node* head)
// {
//     if (head == NULL || head->next == NULL)
//         return head;

//     Node* rest_head = reverseLL(head->next);
//     Node* rest_tail = head->next;
//     rest_tail->next = head;
//     head->next = NULL;
//     return rest_head;
// }

// method 2
Node* reverseLL(Node* curr, Node* prev)
{
    if (curr == NULL)
        return prev;

    Node* next = curr->next;
    curr->next = prev;
    return reverseLL(next, curr);
}


void printList(Node *head)
{
    cout << "\n";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(30);
    head->next->next = new Node(50);
    head->next->next->next = new Node(70);

    printList(head);

    // head = reverseLL(head);
    head = reverseLL(head, NULL);

    printList(head);

    return 0;
}