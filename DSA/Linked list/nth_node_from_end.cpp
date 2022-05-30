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

// both method 1 and method 2 have linear time complexity


// method 1 (using length of linked list)
// void printNthNode(Node *head, int n)
// {
//     if (head == NULL)
//         return;

//     int len = 0;
//     for (Node* curr = head; curr != NULL; curr = curr->next)
//         len++;

//     if (len < n)
//         return;
    
//     Node* curr = head;

//     for (int i = 1; i < (len - n + 1); i++)
//         curr = curr->next;

//     cout << curr->data << endl;
// }


// method 2 : using two pointers
// move first pointer n positons ahead
// start second pointer from head
// move both first and second at the same speed
// when first reaches NULL, second reaches nth pos from last (required position)
void printNthNode(Node *head, int n)
{
    if (head == NULL)
        return;

    Node* first = head, *second = head;

    for(int i = 0; i < n; i++)
    {
        if (first == NULL) return;

        first = first->next;
    }

    while (first != NULL)
    {
        second = second->next;
        first = first->next;
    }

    cout << second->data << endl;

    
}

void printList(Node *head)
{
    cout << "\n";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(25);

    printList(head);
    printNthNode(head, 3);

    printNthNode(head, 1);

    printNthNode(head, 5);

    printNthNode(head, 10);

  
    return 0;
}