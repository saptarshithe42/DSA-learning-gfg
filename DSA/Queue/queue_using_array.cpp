#include <iostream>
using namespace std;

// simple implementation
// struct Queue
// {
//     int sz, cap;
//     int *arr;

//     Queue(int c)
//     {
//         cap = c;
//         sz = 0;
//         arr = new int[cap];
//     }

//     void enqueue(int x)
//     {
//         if (sz == cap)
//             return;

//         arr[sz] = x;
//         sz++;
//     }

//     int dequeue()
//     {
//         if (sz == 0)
//             return INT_MAX;

//         int res = arr[0];

//         for (int i = 0; i < sz - 1; i++)
//         {
//             arr[i] = arr[i + 1];
//         }
//         sz--;
//         return res;
//     }

//     int getFront()
//     {
//         if (sz == 0)
//             return -1;

//         return (0);
//     }

//     int getRear()
//     {
//         if (sz == 0)
//             return -1;

//         return (sz - 1);
//     }

//     int size()
//     {
//         return sz;
//     }

//     bool isEmpty()
//     {
//         return (sz == 0);
//     }

//     bool isFull()
//     {
//         return (sz == cap);
//     }
// };

// efficient implementation (circular array)

struct Queue
{
    int *arr;
    int cap, size, front;

    Queue(int c)
    {
        arr = new int[c];
        cap = c;
        size = 0;
        front = 0;
    }

    void enque(int x)
    {
        if (isFull())
            return;

        int rear = getRear();
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }

    void deque()
    {
        if (isEmpty())
            return;

        front = (front + 1) % cap;
        size--;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        else
            return front;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        else    
            return (front + size -1) % cap;
    }

    bool isFull()
    {
        return (size == cap);
    }

    bool isEmpty()
    {
        return (size == 0);
    }
};

int main()
{
    Queue q(5);

    q.enque(10);
    q.enque(20);

    cout << q.getFront() << endl;
    cout << q.getRear() << endl;

    q.enque(30);
    q.enque(40);

    cout << q.getFront() << endl;
    cout << q.getRear() << endl;

    q.deque();

    cout << q.getFront() << endl;
    cout << q.getRear() << endl;

    q.deque();

    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    

    return 0;
}