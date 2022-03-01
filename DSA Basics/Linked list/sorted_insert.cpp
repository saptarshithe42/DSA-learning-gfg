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

Node *sorted_insert(Node *head, int x)
{
    Node *temp = new Node(x);

    if(head->next == NULL)
    {
        if (x > head->data)
        {
            head->next = temp;
            return head;
        }
        else
        {
            temp->next = head;
            return temp;
        }
    }

    Node *curr = head;

    while (curr->next != NULL)
    {
        if ((x >= curr->data) && (x < curr->next->data))
        {
            temp->next = curr->next;
            curr->next = temp;
            return head;
        }
        curr = curr->next;
    }

    if (x >= curr->data)
    {
        curr->next = temp;
    }
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