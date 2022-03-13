#include <iostream>
using namespace std;

struct Node;
void printList(Node *head);

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};


Node* reverseDLL(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node* curr = head, *prev = NULL; 

    while (curr != NULL)
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }

    return prev->prev;
}




int main()
{

    // Node* head = NULL;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    // Node* head = new Node(10);
    // Node* temp1 = new Node(20);
    // Node* temp2 = new Node(30);

    // head->next = temp1;
    // temp1->prev = head;

    // temp1->next = temp2;
    // temp2->prev = temp1;

    printList(head);

    head = reverseDLL(head);

    printList(head);

    return 0;
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