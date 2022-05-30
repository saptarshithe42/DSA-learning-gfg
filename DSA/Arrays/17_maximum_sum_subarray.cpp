#include<iostream>
using namespace std;


// naive sol 
// time comp : O(n^2)
// int max_subarray_sum(int arr[], int n)
// {
//     int res = arr[0];

//     for(int i = 0; i < n; i++)
//     {
//         int curr = 0;

//         for(int j = i; j < n; j++)
//         {
//             curr = curr + arr[j];
//             res = max(res, curr);
//         }
//     }

//     return res;
// }


// efficient sol
// time comp : O(n)
int max_subarray_sum(int arr[], int n)
{
    int res = arr[0];
    int maxEnding = arr[0];

    for(int i = 1; i < n; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }

    return res;
}


int main()
{
    int arr[] = {20,-10, 30,-80,7,-1,2,3,10};
    int n = 9;

    cout << max_subarray_sum(arr, n) << endl;



    
    return 0;
}