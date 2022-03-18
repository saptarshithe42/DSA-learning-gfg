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



struct Queue
{
    Node* front, *rear;
    int size;

    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void enque(int x)
    {
        Node* temp = new Node(x);
        size++;

        if (front == NULL)
        {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void deque()
    {
        if (front == NULL) return;

        size--;

        Node* temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
    }
};



int main()
{

    Queue q; 
	q.enque(10); 
	q.enque(20); 
	q.deque(); 
	q.deque(); 
	q.enque(30); 
	q.enque(40); 
	q.enque(50); 
	q.deque(); 
	cout << "Queue Front : " << (q.front)->data << endl; 
	cout << "Queue Rear : " << (q.rear)->data; 



    return 0;
}