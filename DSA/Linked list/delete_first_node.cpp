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
Node* deleteLast(Node* head)
{
    if (head == NULL)
        return NULL;
    
    Node* temp = head->next;
    
    delete head;
    return temp;
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