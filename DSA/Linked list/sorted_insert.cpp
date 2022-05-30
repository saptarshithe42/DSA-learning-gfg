#include <iostream>
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

// time complexity : theta(pos), pos is position of node to be inserted
Node *sorted_insert(Node *head, int x)
{
    Node* temp = new Node(x);

    if (head == NULL)
    {
        return temp;
    }

    if (x < head->data)
    {
        temp->next = head;
        return temp;
    }

    Node* curr = head;

    while ((curr->next != NULL) && (curr->next->data < x))
    {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;

    return head;
    
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
    // head->next->next->next = new Node(70);

    int x = 50;

    printList(head);

    head = sorted_insert(head, x);

    printList(head);

    return 0;
}