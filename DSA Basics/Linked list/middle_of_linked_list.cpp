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
// two traversals
// void middleLL(Node *head)
// {
//     if (head == NULL)
//         return;

//     int count = 0;
//     Node *curr = head;
//     while (curr != NULL)
//     {
//         curr = curr->next;
//         count++;
//     }

//     curr = head;

//     int i = 1;
//     while (i != (count / 2) + 1)
//     {
//         curr = curr->next;
//         i++;
//     }
//     cout << curr->data << endl;
// }


// efficient solution
// single traversal
void middleLL(Node* head)
{
    if (head == NULL)
        return;
    
    Node* slow = head;
    Node* fast = head;
    
    while ((fast != NULL) && (fast->next != NULL))
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << slow->data << endl;
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

    Node* head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(25);

    printList(head);
    middleLL(head);


    head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(25);
    head->next->next->next->next->next = new Node(30);

    printList(head);
    middleLL(head);

    head = new Node(10);
    printList(head);
    middleLL(head);

    head = NULL;
    printList(head);
    middleLL(head);



    return 0;
}