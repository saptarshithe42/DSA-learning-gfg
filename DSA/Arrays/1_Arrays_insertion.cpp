#include <iostream>
using namespace std;

int insert(int arr[], int n, int cap, int x, int pos)
{       /* arr - array, n - size of array , cap - capacity of array (max no of elements), 
        x = element to be inserted, 
        pos - position at which to insert x */
    if (n == cap)  // array is full
    {
        return n;   // return old size ,do not insert element
    }

    int idx = pos - 1; // index of the element to be inserted

    for (int i = n - 1; i >= idx; i--) // shift all elements to the right by 1 of given idx
    {
        arr[i + 1] = arr[i];
    }

    arr[idx] = x;  // inserting at given index

    return (n + 1);
}

int main()
{
    int cap = 5;
    int arr[cap] = {5, 10, 20};

    int n = 3;
    int x = 7;
    int pos = 2;
    cout << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    n = insert(arr, n, cap, x, pos);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}