#include <iostream>
using namespace std;

class MinHeap
{
public:
    int *arr;
    int size;
    int capacity;

    MinHeap(int c)
    {
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    // time complexity : O(logn)  (actually O(h) , h = logn for complete binary tree)
    void insert(int x)
    {
        if (capacity == size)
            return;

        size++;
        arr[size - 1] = x;

        for (int i = size - 1; (i != 0) && (arr[parent(i)] > arr[i]);)
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    // time complexity : O(logn)
    // space complexity : O(logn) (for recursive)
    // if you can implement iterative code , space complexity will be O(1)
    void minHeapify(int i)
    {
        int lt = left(i), rt = right(i);
        int smallest = i;

        if (lt < size && arr[lt] < arr[i])
            smallest = lt;

        if (rt < size && arr[rt] < arr[smallest])
            smallest = rt;
        
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    // time complexity : O(logn)
    // space complexity : O(logn) (For recursive)
    // if you can implement iterative code , space complexity can be O(1)
    int extractMin()
    {
        if (size == 0)
            return INT_MAX;
        
        if (size == 1)
        {
            size--;
            return arr[0];
        }

        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify(0);
        return arr[size];
    }
};

int main()
{

    MinHeap h(11);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(20);
    cout << h.extractMin() << " ";
    return 0;
}