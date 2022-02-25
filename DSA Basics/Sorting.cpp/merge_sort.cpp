#include<iostream>
using namespace std;

void merge(int a[], int low, int mid, int high);

void merge_sort(int a[], int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        merge(a, l, m , r);
    }
}

int main()
{
    int arr1[] = {2, 8, 7 , 10};

    cout << "\nInitial array : ";

    for (int x : arr1)
    {
        cout << x << " ";
    }

    merge_sort(arr1, 0, 3);

    cout << "\nSorted array : ";
    for (int x : arr1)
    {
        cout << x << " ";
    }

    cout << endl;


    return 0;
}

void merge(int a[], int low, int mid, int high)
{
    int temp[high+1];

    int i = 0, j = mid + 1, k = 0;
    while ((i <= mid) && (j <= high))
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++; k++;
        }
        else
        {
            temp[k] = a[j];
            j++; k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        i++; k++;
    }

    while (j <= high)
    {
        temp[k] = a[j];
        j++; k++;
    }

    for (int i = 0; i < high+1; i++)
    {
        a[i] = temp[i];
    }
}