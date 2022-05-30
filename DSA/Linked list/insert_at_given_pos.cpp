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

Node *insert_at_pos(Node *head, int pos, int data)
{
    Node *temp = new Node(data);

    if (pos == 1)  // inserting at beginning
    {
        temp->next = head;
        return temp;
    }

    Node *curr = head;

    for (int i = 1; i <= (pos - 2) && curr != NULL; i++)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        return head;
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
    head->next->next->next = new Node(70);

    int pos = 4, data = 20;

    printList(head);

    head = insert_at_pos(head, pos, data);

    printList(head);

    return 0;
}