#include<iostream>
#include<vector>
using namespace std;

// return index of the second largest element

int get_largest(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[res])
        {
            res = i;
        }
    }
    return (res);  //index of largest element
}

// Naive solution O(n) but requires two traversals
// int second_largest(int arr[], int n)
// {
//     int res = -1; //return -1 if no second largest
//     int largest = get_largest(arr, n);

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] != arr[largest])
//         {
//             if (res == -1)
//             {
//                 res = i;
//             }
//             else if (arr[i] > arr[res])
//             {
//                 res = i;
//             }
//         }
//     }

//     return (res);

// }

// efficient solution  - single traversal

int second_largest(int arr[], int n)
{
    int res = -1, largest = 0;
     
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[largest])
        {
            res = largest;
            largest = i;
        }
        else if (arr[i] != arr[largest])
        {
            if ((res == -1) || (arr[i] > arr[res]))
            {
                res =  i;
            }
        }
    }


    return (res);
}









int main()
{

    int a1[] = {10, 5, 8, 20};

    int a2[] = {20, 10, 20, 8, 12};

    int a3[] = {10, 10 ,10};


    cout << second_largest(a1, 4) << "\n";
    cout << second_largest(a2, 5) << "\n";
    cout << second_largest(a3, 3) << "\n";

    
    return 0;
}