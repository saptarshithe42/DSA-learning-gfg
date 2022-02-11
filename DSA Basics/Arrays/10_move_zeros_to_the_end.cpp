#include<iostream>
using namespace std;

// naive sol - O(n^2) time, theta(1) space
// void move_zeros_to_end(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 0)
//         {
//             for(int j = i+1; j < n; j++)
//             {
//                 if (arr[j] != 0)
//                 {
//                     swap(arr[i], arr[j]);
//                 }
//             }
//         }
//     }
// }

// Efficient sol - O(n) time, O(1) aux space
void move_zeros_to_end(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

int main()
{
    int a1[] = {8, 5, 0, 10, 0, 20};
    move_zeros_to_end(a1, 6);

    cout << "\n";
    for (int x : a1)
    {
        cout << x << " ";
    }

    int a2[] = {0, 0 , 0, 10, 0};
    move_zeros_to_end(a2, 5);
    cout << "\n";
    for (int x : a2)
    {
        cout << x << " ";
    }

    int a3[] = {10, 20};
    move_zeros_to_end(a3, 2);
    cout << "\n";
    for (int x : a3)
    {
        cout << x << " ";
    }


    
    return 0;
}