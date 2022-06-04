#include<iostream>
#include "singly_linked_list_node.h"
using namespace std;
void traverse_linked_lists(Node *head);

void pairwise_swap(Node* head)
{
    if(head == NULL || head->next == NULL)
        return;

    Node* curr = head;

    while(curr != NULL && curr->next != NULL)
    {
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
}


int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    traverse_linked_lists(head);
    cout << endl;

    pairwise_swap(head);

    traverse_linked_lists(head);
    cout << endl;

    return 0;
}

void traverse_linked_lists(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {

        cout << curr->data << " ";
        curr = curr->next;
    }
}