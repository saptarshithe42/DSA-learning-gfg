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

void traverse_linked_lists(Node *head);

// time comp : O(n)
// aux sp : O(n / k)
// Node *reverseK(Node *head, int k)
// {
//     Node *curr = head, *next = NULL, *prev = NULL;
//     int count = 0;
//     while (curr != NULL && count < k)
//     {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//         count++;
//     }
//     if (next != NULL)
//     {
//         Node *rest_head = reverseK(next, k);
//         head->next = rest_head;
//     }
//     return prev;
// }

// time comp : O(n)
// aux sp : O(1)
Node *reverseK(Node *head, int k)
{
    Node *curr = head, *prevFirst = NULL;
    bool isFirstPass = true;
    while (curr != NULL)
    {
        Node *first = curr, *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (isFirstPass)
        {
            head = prev;
            isFirstPass = false;
        }
        else
        {
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return head;
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

    int k = 3;

    Node *new_head = reverseK(head, k);
    // Node *new_head = reverse_in_groups_iterative(head, k);

    traverse_linked_lists(new_head);

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