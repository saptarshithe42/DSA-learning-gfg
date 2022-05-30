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

// naive solution
// traversing till last node and then entering
// time complexity : O(n)
// Node* insertBegin(Node* head, int x)
// {
//     Node* temp = new Node(x);

//     if (head == NULL) // if LL is initially empty
//     {
//         temp->next = temp;
//     }
//     else
//     {
//         Node* curr = head;
//         while(curr->next != head)
//             curr = curr->next;

//         curr->next = temp;
//         temp->next = head;
//     }

//     return temp;

// }


// O(1) time solution
// my sol
// actually logic as gfg sol
// Node* insertBegin(Node* head, int x)
// {
//     Node* temp = new Node(x);

//     if (head == NULL)
//     {
//         temp->next = temp;
//         return temp;
//     }
//     else
//     {
//         swap(head->data, temp->data);

//         temp->next = head->next;
//         head->next =temp;
//     }

//     return head;

// }



// gfg sol
Node* insertBegin(Node* head, int x)
{
    Node* temp = new Node(x);

    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next =temp;
        int t = head->data;
        head->data = temp->data;
        temp->data = t;
        return head;
    }
}



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

    // Node* head = new Node(10);
    // head->next = head;
    

    // Node* head = NULL;

    printList(head);
    int x = 2;

    head = insertBegin(head, x);

    printList(head);


    
    
    return 0;
}

