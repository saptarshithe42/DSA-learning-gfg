#include<iostream>
#include "singly_linked_list_node.h"
using namespace std;
void traverse_linked_lists(Node *head);

void delNode(Node* ptr)
{
    Node* temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete temp;
}


int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    traverse_linked_lists(head);
    cout << endl;

    delNode(head->next->next);

    traverse_linked_lists(head);

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