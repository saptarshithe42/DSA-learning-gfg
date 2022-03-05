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


// naive solution
// time complexity : theta(n)

// Node* deleteHead(Node* head)
// {
//     if (head == NULL)
//     {
//         return NULL;
//     }
//     if (head->next == head)
//     {
//         delete head;
//         return NULL;
//     }

//     Node* curr = head;
//     while (curr->next != head)
//         curr = curr->next;

//     curr->next = head->next;

//     delete head;
//     return (curr->next);
// }

// efficient solution
Node* deleteHead(Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == head)
    {
        delete head;
        return NULL;
    }

    head->data = head->next->data;
    Node* temp = head->next;
    head->next = temp->next;
    delete temp;
    return head;
}



void printList(Node *head)
{
    if (head == NULL)
        return;

    Node *p = head;
    cout << "\n";
    do
    {
        cout << (p->data) << " ";
        p = p->next;
    } while (p != head);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;

    // Node* head = new Node(10);
    // head->next = head;

    // Node* head = NULL;

    printList(head);

    head = deleteHead(head);

    printList(head);

    return 0;
}
