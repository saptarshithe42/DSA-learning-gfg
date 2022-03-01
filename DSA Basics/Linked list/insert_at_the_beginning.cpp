#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// time complexity : O(1)
Node* insert_at_beginning(Node* head, int x)
{
    Node* new_head = new Node(x);
    new_head->next = head;

    return new_head;
}

void printList(Node* head)
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
    // 10 -> 20 -> 30
    // Node* head = new Node(10);
    // head->next = new Node(20);
    // head->next->next = new Node(30);


    Node* head = NULL;




    printList(head);

    int x = 5;

    head = insert_at_beginning(head, x);

    printList(head);






    return 0;
}