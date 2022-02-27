#include<iostream>
using namespace std;

int hoare_partition(int arr[], int l, int h);

// quick sort with lomuto partitioning

// worst case time : O(n^2)
// average case time : O(nlogn)
// space complexity : theta(n) for worst case (recursive call stack), theta(logn) in best case
void quick_sort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = hoare_partition(arr, l, h);
        quick_sort(arr, l, p);
        quick_sort(arr, p+1, h);
    }
}

// tail call elimination
// void quick_sort(int arr[], int l, int h)
// {
//     Begin:
//     if (l < h)
//     {
//         int p = hoare_partition(arr, l, h);
//         quick_sort(arr, l, p);
//         l = p + 1;
//         goto Begin;
//     }
// }

int main()
{

     int a[] = {10, 5, 30, 15, 7};
    int l = 0, r = 4;

    cout << "\nInitial array : ";

    for (int x : a)
    {
        cout << x << " ";
    }
    quick_sort(a, l, r);

    cout << "\nSorted array : ";
    for (int x : a)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;

    
    return 0;
}

int hoare_partition(int arr[], int l, int h)
{
    int i = l - 1, j = h + 1;
    int pivot = arr[l];

    while (true)
    {
        do
        {
            i++;
        } while(arr[i] < pivot);
        do
        {
            j--;
        } while(arr[j] > pivot);

        if (i >= j) return j;

        swap(arr[i], arr[j]);
    }
}