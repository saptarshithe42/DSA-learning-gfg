#include<iostream>
using namespace std;

int lomuto_partition(int arr[], int l, int h);

// quick sort with lomuto partitioning

// worst case time : O(n^2)
// average case time : O(nlogn)
// space complexity : O(1)
void quick_sort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = lomuto_partition(arr, l, h);
        quick_sort(arr, l, p-1);
        quick_sort(arr, p+1, h);
    }
}

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

int lomuto_partition(int arr[], int l, int h)
{
    int i = l - 1;
    int pivot = arr[h];
    for(int j = l; j <= h-1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[h]);

    return (i+1);
}