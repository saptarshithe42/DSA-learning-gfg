#include<iostream>
using namespace std;
// find maxm diff (arr[j] - arr[i]) such that j > i.

// naive solution
// time complexity : O(n^2)


int  maximum_difference(int arr[], int n)
{
    int max = arr[1] - arr[0];

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if ((arr[j] - arr[i]) > max)
                max = (arr[j] - arr[i]);
        }
    }



    return max;

}

// efficient solution
// time comp : theta(n)
// prints left to right
// void maximum_difference(int arr[], int n)
// {
//     int curr_ldr = arr[n-1];
//     cout << curr_ldr << " ";

//     for (int i = n-2; i >= 0; i--)
//     {
//         if (arr[i] > curr_ldr)
//         {
//             curr_ldr = arr[i];
//             cout << curr_ldr << " ";
//         }
//     }

// }



int main()
{
    int a1[] = {2,3,10,6,4,8,1};
    cout << maximum_difference(a1, 7);
    cout << endl;


    int a2[] = {7,9,5,6,3,2};
    cout << maximum_difference(a2, 6);
    cout << endl;


    int a3[] = {10,20,30};
    cout << maximum_difference(a3, 3);
    cout << endl;

    int a4[] = {30,10,8,2};
    cout << maximum_difference(a4, 4);
    cout << endl;
   
    
    return 0;
}