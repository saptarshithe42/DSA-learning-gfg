#include<iostream>
#include "singly_linked_list_node.h"
using namespace std;
void traverse_linked_lists(Node *h1);

// time comp : O(c1 + c2)
// aux sp : O(1)
int intersection_point_of_two_LLs(Node* h1, Node* h2)
{
    int c1 = 0, c2 = 0;

    for(Node* curr = h1; curr != NULL; curr = curr->next)
        c1++;

    for(Node* curr = h2; curr != NULL; curr = curr->next)
        c2++;

    int diff = abs(c1 - c2);

        Node* curr1 = h1 , *curr2 = h2;
        if(c1 > c2)
        {
            while(diff--)
            {
                curr1 = curr1->next;
            }
        }
        else
        {
            while(diff--)
            {
                curr2 = curr2->next;
            }
        }


        while(curr1 != NULL && curr2 != NULL)
        {
            if(curr1 == curr2)
                return curr1->data;


            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return (-1);

}




int main()
{
    Node* h1 = new Node(1);
    h1->next = new Node(2);
    h1->next->next = new Node(3);
    h1->next->next->next = new Node(4);
    h1->next->next->next->next = new Node(5);
    h1->next->next->next->next->next = new Node(6);

    Node* h2 = new Node(1);
    h2->next = new Node(2);
    h2->next->next = new Node(3);
    h2->next->next->next = h1->next->next->next;
    h2->next->next->next->next = h1->next->next->next->next;
    h2->next->next->next->next->next = h1->next->next->next->next->next;

    traverse_linked_lists(h1);
    cout << endl;
    traverse_linked_lists(h2);
    cout << endl;

    cout << intersection_point_of_two_LLs(h1, h2) << endl;
    


    return 0;
}

void traverse_linked_lists(Node *h1)
{
    Node *curr = h1;
    while (curr != NULL)
    {

        cout << curr->data << " ";
        curr = curr->next;
    }
}