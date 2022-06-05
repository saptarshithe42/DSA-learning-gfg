#include<iostream>
#include "singly_linked_list_node.h"
using namespace std;

void traverse_linked_lists(Node* head);


Node* mergeSortedLLs(Node* h1, Node* h2)
{
    Node* head = NULL;

    if(h1 == NULL)
    {
        return h2;
    }
    if(h2 == NULL)
    {
        return h1;
    }

    Node* curr1 = h1, *curr2 = h2, *tail = NULL;
    if(h1->data < h2->data)
    {
        head = h1;
        curr1 = curr1->next;
    }
    else
    {
        head = h2;
        curr2 = curr2->next;
    }

    tail = head;

    while(curr1 != NULL && curr2 != NULL)
    {
        if(curr1->data < curr2->data)
        {
            tail->next = curr1;
            tail = tail->next;
            curr1 = curr1->next;
        }
        else
        {
            tail->next = curr2;
            tail = tail->next;
            curr2 = curr2->next;
        }
    }

    if(curr1 != NULL)
    {
        tail->next = curr1;
    }

    if(curr2 != NULL)
    {
        tail->next = curr2;
    }

    return head;
}


int main()
{
    Node* h1 = new Node(10);
    h1->next = new Node(20);
    h1->next->next = new Node(30);
    h1->next->next->next = NULL;

    traverse_linked_lists(h1);
    cout << endl;

    Node* h2 = new Node(5);
    h2->next = new Node(25);
    h2->next->next = NULL;

    traverse_linked_lists(h2);
    cout << endl;

    Node* mergedList = mergeSortedLLs(h1, h2);

    traverse_linked_lists(mergedList);
    cout << endl;

    
    return 0;
}

void traverse_linked_lists(Node* head)
{
    Node* curr = head;
    while (curr != NULL)
    {
        
        cout << curr->data << " ";
        curr = curr->next;
    }
}