#include<iostream>
#include "singly_linked_list_node.h"
using namespace std;
void traverse_linked_lists(Node *head);

Node* segregate_even_odd(Node* head)
{
    Node* eS = NULL, *eE = NULL, *oS = NULL,  *oE = NULL;

    for(Node* curr = head; curr != NULL; curr = curr->next)
    {
        int x = curr->data;

        if(x % 2 == 0)
        {
            if (eS == NULL)
            {
                eS = curr;
                eE = eS;
            }
            else
            {
                eE->next = curr;
                eE = eE->next;
            }
        }
        else
        {
            if (oS == NULL)
            {
                oS = curr;
                oE = oS;
            }
            else
            {
                oE->next = curr;
                oE = oE->next;
            }
        }
    }

    if(oS == NULL || eS == NULL)
    {
        return head;
    }

    eE->next = oS;
    oE->next = NULL;
    return eS;
}


int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    traverse_linked_lists(head);
    cout << endl;

    Node* new_head = segregate_even_odd(head);
    

    traverse_linked_lists(new_head);

    return 0;
}

void traverse_linked_lists(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {

        cout << curr->data << " ";
        curr = curr->next;
    }
}