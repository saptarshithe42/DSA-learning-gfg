#include <iostream>
using namespace std;

// simple implementation
// struct Deque
// {
//     int size, cap;
//     int* arr;

//     Deque(int c)
//     {
//         cap = c;
//         size = 0;
//         arr = new int[cap];
//     }

//     void insertFront(int x)
//     {
//         if (isEmpty())
//             return;

//         for (int i = size-1; i >= 0; i--)
//         {
//             arr[i+1] = arr[i];
//         }
//         arr[0] = x;
//         size++;
//     }

//     void deleteFront()
//     {
//         if (isEmpty())
//             return;

//         for (int i = 0; i < size-1; i++)
//         {
//             arr[i] = arr[i+1];
//         }
//         size--;
//     }

//     int getFront()
//     {
//         if (isEmpty())
//             return -1;
//         else
//             return 0;
//     }

//     void insertRear(int x)
//     {
//         if (isFull())
//             return;

//         arr[size] = x;
//         size++;
//     }

//     void deleteRear()
//     {
//         if (isEmpty())
//             return;

//         size--;
//     }

//     int getRear()
//     {
//         if (isEmpty())
//             return -1;
//         else
//             return (size - 1);
//     }

//     bool isFull()
//     {
//         return (size == cap);
//     }

//     bool isEmpty()
//     {
//         return (size == 0);
//     }
// };

// efficient implementation (using circular array)

struct Deque
{
    int *arr;
    int cap, front, size;

    Deque(int c)
    {
        arr = new int[c];
        cap = c;
        size = 0;
        front = 0;
    }

    void insertFront(int x)
    {
        if (isFull())
            return;
        
        front = (front - 1 + cap) % cap;
        arr[front] = x;
        size++;
    }

    void deleteFront()
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
            return (front);
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        else    
            return (front + size - 1) % cap;
    }

    void insertRear(int x)
    {
        if (isFull()) 
            return;
        
        int new_rear = (front + size) % cap;
        arr[new_rear] = x;
        size++;
    }

    void deleteRear()
    {
        if (isEmpty()) 
            return;

        size--;
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

    Deque dq(5);

    dq.insertRear(10);
    dq.insertFront(20);
    cout << dq.getFront() << endl;
    dq.insertFront(30);
    dq.insertRear(40);
    cout << dq.getRear() << endl;
    dq.deleteRear();
    dq.deleteFront();
    cout << dq.getFront() << endl;
    cout << dq.getRear() << endl;

    return 0;
}