#include <iostream>
using namespace std;
struct Node;

Node* deleteHead(Node* head);

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

Node* deleteKthNode(Node* head, int k)
{
    if (head == NULL) return NULL;

    if (k == 1)
    {
        deleteHead(head);
    }

    Node* curr = head;
    for (int i = 0; i < k-2; i++)
    {
        curr = curr->next;
    }

    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete (temp);

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
    int k = 3;

    head = deleteKthNode(head, k);

    printList(head);

    return 0;
}

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