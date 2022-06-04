#include <iostream>
#include "singly_linked_list_node.h"
using namespace std;

void traverse_linked_lists(Node *head);

void detect_and_remove_loop(Node *head)
{

    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
    {
        return;
    }

    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

int main()
{
    // without loop
    // Node *head = new Node(10);
    // head->next = new Node(20);
    // head->next->next = new Node(30);
    // head->next->next->next = new Node(40);
    // head->next->next->next->next = new Node(50);
    // head->next->next->next->next->next = new Node(60);

    // with loop
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    head->next->next->next->next->next->next = head->next;

    detect_and_remove_loop(head);

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