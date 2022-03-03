#include<iostream>
#include<vector>
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

// my sol
// void remove_dup(Node* head)
// {
//     if (head == NULL || head->next == NULL)
//         return;

//     Node* curr = head, *next = curr->next;

//     while (curr != NULL &&  next != NULL)
//     {
//         if (curr->data == next->data)
//         {
//             next = next->next;
//             delete (curr->next);
//             curr->next = next;
//         }
//         else
//         {
//             curr = curr->next;
//             next = next->next;
//         }
//     }
// }

// gfg sol
void remove_dup(Node* head)
{
    Node* curr = head;

    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete (temp);
        }
        else
            curr = curr->next;
    }
}


void printList(Node *head)
{
    cout << "\n";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{

    // Node *head = new Node(10);
    // head->next = new Node(30);
    // head->next->next = new Node(50);
    // head->next->next->next = new Node(50);
    // head->next->next->next->next = new Node(70);

    Node *head = new Node(10);
    head->next = new Node(10);
    head->next->next = new Node(30);
    head->next->next->next = new Node(50);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(50);

    printList(head);

    remove_dup(head);

    printList(head);

    return 0;
}