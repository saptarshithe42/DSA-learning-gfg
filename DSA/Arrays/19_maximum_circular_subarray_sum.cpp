#include<iostream>
using namespace std;

#include<iostream>
using namespace std;


// naive sol
// time comp : O(n^2)
// int maximum_circular_subarray_sum(int arr[], int n)
// {
//     int res = arr[0];

//     for(int i = 0; i < n; i++)
//     {
//         int curr_sum = arr[i];
//         int curr_max = arr[i];

//         for(int j = 1; j < n; j++)
//         {
//             int index = (i + j) % n;
//             curr_sum += arr[index];
//             curr_max = max(curr_max, curr_sum);
//         }

//         res = max(res, curr_max);
//     }

//     return res;
// }


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



// efficient sol
// time com : theta(n)
int maximum_circular_subarray_sum(int arr[], int n)
{
    int max_normal = max_subarray_sum(arr, n);

    if(max_normal < 0)
    {
        return max_normal;
    }

    int arr_sum = 0;
    
    for(int i = 0; i < n; i++)
    {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }

    int max_circular = arr_sum + max_subarray_sum(arr, n);

    return max(max_normal, max_circular);
    
}


int main()
{

    int arr[] = {8,-4,3,-5,4};
    int n = 5;

    // int arr[] = {7, 10, 13, 14};
    // int n = 4;


    // int arr[] = {10,12,8,4};
    // int n = 4;

    cout << maximum_circular_subarray_sum(arr, n) << endl;



    
    return 0;
}


    