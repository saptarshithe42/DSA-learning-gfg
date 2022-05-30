#include <iostream>
using namespace std;


// Naive solution  theta(nd) time, and theta(1) space
// my sol
// void left_rotate_d_places(int a[], int n, int d)
// {
//     for (int j = 1; j <= d; j++)
//     {
//         int temp = a[0];

//         for (int i = 1; i < n; i++)
//         {
//             a[i - 1] = a[i];
//         }

//         a[n - 1] = temp;
//     }
// }



// Naive solution  theta(nd) time, and theta(1) space
// gfg sol
// void left_rotate_arr_one(int arr[], int n)
// {
//     int first = arr[0];

//     for (int i = 1; i < n; i++)
//     {
//         arr[i-1] = arr[i];
//     }

//     arr[n - 1] = first;
// }

// void left_rotate_d_places(int a[], int n, int d)
// {
//     for (int j = 1; j <= d; j++)
//     {
//         left_rotate_arr_one(a, n);
//     }
// }

// new improved - theta(n) time , theta(d) aux space
// my sol (same as gfg sol)
// void left_rotate_d_places(int a[], int n, int d)
// {
//     int rotarr[d];

//     for (int i = 0; i < d; i++)
//     {
//         rotarr[i] = a[i];
//     }

//     for (int i = d; i < n; i++)
//     {
//         a[i-d] = a[i];
//     }
    

//     // int j = 0;
//     // for (int i = (n - d); i < n; i++)
//     // {
//     //     a[i] = rotarr[j];
//     //     j++;
//     // }

//     //the upper loop can be shortened as :-
//     for (int i = 0; i < d; i++)
//     {
//         a[n - d + i] = rotarr[i];
//     }
// }


// Even better -> theta(n) time, theta(1) aux space
// Reversal algorithm
void reverse(int arr[], int low, int high)
{
    //low and high are indexes and both are included
    while (low < high)
    {
        // int temp = arr[low];
        // arr[low] = arr[high];
        // arr[high] = temp;
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}


void left_rotate_d_places(int a[], int n, int d)
{
    reverse(a, 0, d - 1); // reverse first d elements
    reverse(a, d, n-1); // reverse remaining (n-d) elements
    reverse(a, 0, n-1); //reverse the whole array
}




int main()
{
    int a1[] = {1, 2, 3, 4, 5};
    int d = 2;
    left_rotate_d_places(a1, 5, d);

    cout << "\n";
    for (int x : a1)
    {
        cout << x << " ";
    }

    int a2[] = {10, 5, 30, 15};
    d = 3;

    left_rotate_d_places(a2, 4, d);

    cout << "\n";
    for (int x : a2)
    {
        cout << x << " ";
    }

    return 0;
}