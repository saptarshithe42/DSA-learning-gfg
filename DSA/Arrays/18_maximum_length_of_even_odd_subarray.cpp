#include<iostream>
using namespace std;

// naive sol 
// time comp : O(n^2)
// my naive sol
// int maxLengthOfEvenOddSubarray(int arr[], int n)
// {
//     int res = 1;

//     for(int i = 0; i < n; i++)
//     {
//         int count = 1;
//         bool even = (arr[i] % 2 == 0) ? true : false;
//         for(int j = i+1; j < n; j++)
//         {
//             if((arr[j] % 2 != 0) && (even == true))
//             {
//                 count++;
//                 res = max(res, count);
//             }
//             else if((arr[j] % 2 == 0) && (even == false))
//             {
//                 count++;
//                 res = max(res, count);
//             }
//             else
//             {
//                 break;
//             }

//             even = (arr[j] % 2 == 0) ? true : false;
//         }
//     }

//     return res;

// }


// naive sol  gfg
// time comp : O(n^2)

// int maxLengthOfEvenOddSubarray(int arr[], int n)
// {
//     int res = 1;

//     for(int i = 0; i < n; i++)
//     {
//         int curr = 1;
//         for(int j = i+1; j < n; j++)
//         {
//             if((arr[j] % 2 == 0 && arr[j-1] % 2 != 0) || (arr[j] % 2 != 0 && arr[j-1] % 2 == 0))
//             {
//                 curr++;
//             }
//             else
//             {
//                 break;
//             }
//         }

//         res = max(res, curr);
//     }

//     return res;

// }


// efficient sol
// time comp : O(n)

int maxLengthOfEvenOddSubarray(int arr[], int n)
{
   int res = 1, curr = 1;

   for(int i = 1; i < n; i++)
   {
       if((arr[i] % 2 == 0 && arr[i-1] % 2 != 0) ||(arr[i] % 2 != 0 && arr[i-1] % 2 == 0))
        {
            curr++;
            res = max(res, curr);
        }
        else
        {
            curr = 1;
        }
   }
   return res;
}


int main()
{

    int arr[] = {10,12,14,7,8};
    int n = 5;

    // int arr[] = {7, 10, 13, 14};
    // int n = 4;


    // int arr[] = {10,12,8,4};
    // int n = 4;

    cout << maxLengthOfEvenOddSubarray(arr, n) << endl;



    
    return 0;
}