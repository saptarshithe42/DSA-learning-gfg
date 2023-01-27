#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }

};

void display(Node* head)
{
    Node* curr = head;
    cout << "\n";
    while(curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

int main()
{
    Node* h1 = new Node(1);
    h1->next = new Node(3);
    h1->next->next = new Node(6);
    h1->next->next->next = new Node(9);

    display(h1);


    Node* h2 = new Node(1);
    h2->next = new Node(2);
    h2->next->next = new Node(5);
    h2->next->next->next = new Node(7);

    display(h2);

    Node* head = NULL;
    Node* curr1 = NULL, *curr2 = NULL, *next1 = NULL, *next2 = NULL;
    Node* prev1 = NULL, *prev2 = NULL;

    if(h1->data <= h2->data)
    {
        head = h1;
        curr1 = h1;
        curr2 = h2;
    }
    else
    {
        head = h2;
        curr1 = h2;
        curr2 = h1;
    }

    while(1)
    {
        while(curr1 != NULL && curr1->data <= curr2->data)
        {
            prev1 = curr1;
            curr1 = curr1->next;
        }

        prev1->next = curr2;

        if(curr1 == NULL)
        {
            break;
        }

        while(curr2 != NULL && curr2->data <= curr1->data)
        {
            prev2 = curr2;
            curr2 = curr2->next;
        }

        prev2->next = curr1;

        if(curr2 == NULL)
        {
            break;
        }
    }

    display(head);


}