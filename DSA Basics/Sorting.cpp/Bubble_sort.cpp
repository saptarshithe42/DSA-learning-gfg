#include<iostream>
using namespace std;

// void bubble_sort(int arr[], int n)
// {
//     for (int i = 0; i < n-1; i++)
//     {
//         for (int j = 0; j < n-1; j++)
//         {
//             if (arr[j] > arr[j+1])
//             {
//                 swap(arr[j], arr[j+1]);
//             }
//         }
//     }
// }

// not going till end after 1st pass,
// as in i-th iteration , last i elements are already in correct position
// void bubble_sort(int arr[], int n)
// {
//     for (int i = 0; i < n-1; i++)
//     {
//         for (int j = 0; j < n-1-i; j++)
//         {
//             if (arr[j] > arr[j+1])
//             {
//                 swap(arr[j], arr[j+1]);
//             }
//         }
//     }
// }

// optimized solution (to stop when array is sorted / becomes sorted in the middle)
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            // cout << "\nArray is sorted, stopping after " << (i+1) << "th pass"<< endl;
            break;
        }
    }
}

int main()
{  
    // int arr1[] = {2, 10, 8, 7};
    int arr1[] = {2, 8, 7 , 10};

    cout << "\nInitial array : ";

    for (int x : arr1)
    {
        cout << x << " ";
    }

    bubble_sort(arr1, 4);

    cout << "\nSorted array : ";
    for (int x : arr1)
    {
        cout << x << " ";
    }

    cout << endl;


    return 0;
}