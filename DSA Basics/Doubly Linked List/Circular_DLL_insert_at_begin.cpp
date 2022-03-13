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

Node *insertAtHead(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
    }

    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;

    return temp;
}

Node *insertAtEnd(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
    }

    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;

    return head;
}

int main()
{

    // Node* head = NULL;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    head->next->next->next = head;
    head->prev = head->next->next;

    // Node* head = new Node(10);
    // Node* temp1 = new Node(20);
    // Node* temp2 = new Node(30);

    // head->next = temp1;
    // temp1->prev = head;

    // temp1->next = temp2;
    // temp2->prev = temp1;

    // temp2->next = head;
    // head->prev = temp2;

    printList(head);

    head = insertAtHead(head, 55);

    printList(head);

    head = insertAtEnd(head, 56);

    printList(head);

    return 0;
}

void printList(Node *head)
{
    cout << "\n";
    if (head == NULL)
        return;
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}