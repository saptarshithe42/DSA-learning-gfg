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

Node* insert_at_end(Node* head, int x)
{
    Node* temp = new Node(x);

    if (head == NULL)
    {
        return (temp);
    }

    Node* curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = temp;

    return head;

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
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    head = insert_at_end(head, 40);

    printList(head);



    return 0;
}