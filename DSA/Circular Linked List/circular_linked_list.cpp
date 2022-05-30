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


// method 1  (for loop)
// void printList(Node *head)
// {
//     if (head == NULL) return;

//     cout << head->data << " ";
//     for(Node* curr = head->next; curr != head; curr = curr->next)
//     {
//         cout << curr->data << " ";
//     }
// }


// method 2  (do-while loop)
void printList(Node *head)
{
    if (head == NULL) return;

    Node* p = head;
    cout << "\n";
    do{
        cout << (p->data) << " ";
        p = p->next;
    }while(p != head);
}


int main()
{
    Node* head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;

    printList(head);


    
    
    return 0;
}

