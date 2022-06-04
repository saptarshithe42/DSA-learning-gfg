#include <iostream>
#include "singly_linked_list_node.h"
using namespace std;


// Floyd's loop detection algorithm
// time comp : O(n)
// Aux sp : O(1)
bool isLoop(Node* head)
{
    Node* slow = head, *fast = head;


    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }

    return false;
}


int main()
{
    // without loop
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);


    // with loop
    // Node *head = new Node(10);
    // head->next = new Node(20);
    // head->next->next = new Node(30);
    // head->next->next->next = new Node(40);
    // head->next->next->next->next = new Node(50);
    // head->next->next->next->next->next = new Node(60);
    // head->next->next->next->next->next->next = head->next;

    cout << std::boolalpha;

    cout << isLoop(head) << endl;

    return 0;
}

