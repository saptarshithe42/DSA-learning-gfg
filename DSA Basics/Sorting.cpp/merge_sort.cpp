#include <iostream>
using namespace std;

void merge(int a[], int low, int mid, int high);

void merge_sort(int a[], int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
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
    merge_sort(a, l, r);

    cout << "\nSorted array : ";
    for (int x : a)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}

void merge(int arr[], int l, int m, int h)
{

    int n1 = m - l + 1, n2 = h - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];


        
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

// void merge(int a[], int low, int mid, int high)
// {
//     int n1 = mid - low + 1 , n2 = high - mid;
//     int left[n1], right[n2];

//     for (int i = 0; i < n1; i++)
//     {
//         left[i] = a[low + i];
//     }
//     for(int i = 0; i < n2; i++)
//     {
//         right[i] = a[mid + i + 1];
//     }

//     int i = 0, j = 0, k = 0;
//     while ((i < n1) && (j < n2))
//     {
//         if (left[i] <= right[j])
//         {
//             a[k] = left[i];
//             i++; k++;
//         }
//         else
//         {
//             a[k] = right[j];
//             j++; k++;
//         }
//     }

//     while (i < n1)
//     {
//         a[k] = left[i];
//         i++; k++;
//     }

//     while (j < n2)
//     {
//         a[k] = right[j];
//         j++; k++;
//     }
// }