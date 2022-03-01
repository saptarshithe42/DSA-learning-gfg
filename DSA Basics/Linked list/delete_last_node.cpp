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

// time complexity : O(n)
Node* deleteLast(Node* head)
{
    if (head == NULL)  // head is NULL
        return NULL;

    if (head->next == NULL)  // Just one node in the list
        return NULL;
    

    Node* curr = head;

    while(curr->next->next != NULL)
    {
        curr = curr->next;
    }

    delete (curr->next);

    curr->next = NULL;
    
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


    printList(head);

    head = deleteLast(head);

    printList(head);



    return 0;
}