#include<iostream>
using namespace std;

// naive solution
// time complexity : O(n^2)
// void odd_occuring(int arr[], int n)
// {
//     for(int i = 0; i < n; i++)
//     {
//         int count = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[i] == arr[j])
//             {
//                 count++;
//             }
//         }

//         if (count % 2 != 0)
//         {
//             cout << arr[i] << endl;
//             return;
//         }
//     }
// }

// efficient solution
// time complexity : O(n)
// aux space : O(1)
void odd_occuring(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res ^ arr[i];
    }

    cout << res << endl;
}

int main()
{
    int arr1[] = {4,3,4,4,4,5,5};
    odd_occuring(arr1, 7);

    int arr2[] = {8,7,7,8,8};
    odd_occuring(arr2, 5);



    return 0;
}