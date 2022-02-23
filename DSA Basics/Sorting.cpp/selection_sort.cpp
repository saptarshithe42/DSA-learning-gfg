#include<iostream>
#include<limits>
using namespace std;

// naive solution, using extra array
// void selection_sort(int arr[], int n)
// {
//     int temp[n];

//     for (int i = 0; i < n; i++)
//     {
//         int min_ind = 0;
//         for(int j = 1; j < n; j++)
//         {
//             if (arr[j] < arr[min_ind])
//             {
//                 min_ind = j;
//             }
//         }

//         temp[i] = arr[min_ind];
//         arr[min_ind] = std::numeric_limits <int>::max();
//     }

//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = temp[i];
//     }
// }

// in place change, optimized
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min_ind = i;

        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }
        swap(arr[min_ind], arr[i]);
    }
}

int main()
{
    int arr1[] = {2, 4, 3, 1};

    cout << "\nInitial array : ";

    for (int x : arr1)
    {
        cout << x << " ";
    }

    selection_sort(arr1, 4);

    cout << "\nSorted array : ";
    for (int x : arr1)
    {
        cout << x << " ";
    }

    return 0;
}