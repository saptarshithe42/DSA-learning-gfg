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

// iterative
// int searchLL(Node* head, int x)
// {
//     int pos = 1;
    
//     while (head != NULL)
//     {
//         if (head->data == x)
//         {
//             return pos;
//         }
//         pos++;
//         head = head->next;
//     }

//     return -1;
// }

// recursive
int searchLL(Node* head, int x)
{
    if (head == NULL)
        return -1;

    if (head->data == x)
        return 1;

    else
    {
        int res = searchLL(head->next, x);
        if (res == -1)
            return -1;
        else
            return (res+1);
    }

}


int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int n1 = searchLL(head, 20);
    int n2 = searchLL(head, 40);
    int n3 = searchLL(head, 55);

    cout << n1 << endl;
    cout << n2 << endl;
    cout << n3 << endl;
    
    return 0;
}