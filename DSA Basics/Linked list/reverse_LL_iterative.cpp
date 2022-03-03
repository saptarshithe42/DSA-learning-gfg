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

// naive solution
// two traversals
// O(n) extra space
// Node* reverseLL(Node* head)
// {
//     vector<int> arr;

//     for (Node* curr = head; curr != NULL; curr = curr->next)
//     {
//         arr.push_back(curr->data);
//     }
//     for (Node* curr = head; curr != NULL; curr = curr->next)
//     {
//         curr->data = arr.back();
//         arr.pop_back();
//     }

//     return head;
// }

//efficient solution
Node* reverseLL(Node* head)
{
    Node* curr = head, *prev = NULL;

    while (curr != NULL)
    {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
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

    Node *head = new Node(10);
    head->next = new Node(30);
    head->next->next = new Node(50);
    head->next->next->next = new Node(70);

    printList(head);

    head = reverseLL(head);

    printList(head);

    return 0;
}