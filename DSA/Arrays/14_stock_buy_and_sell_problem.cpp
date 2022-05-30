#include <iostream>
#include <stack>
using namespace std;


// gfg efficient sol

int maxProfit(int arr[], int n)
{
    int profit = 0;

    for(int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i-1])
            profit += (arr[i] - arr[i-1]);
    }

    return profit;
}


// my sol
// int maxProfit(int arr[], int n)
// {
//     stack<int> s;
//     int profit = 0;

//     s.push(arr[0]);
//     for (int i = 1; i < n; i++)
//     {
//         if (s.size() == 1)
//         {
//             if (arr[i] < s.top())
//             {
//                 s.pop();
//                 s.push(arr[i]);
//             }
//             else if (arr[i] > s.top())
//             {
//                 s.push(arr[i]);
//             }
//         }
//         else if (s.size() == 2)
//         {
//             if (arr[i] > s.top())
//             {
//                 s.pop();
//                 s.push(arr[i]);
//             }
//             else if (arr[i] < s.top())
//             {
//                 profit += s.top();
//                 s.pop();
//                 profit -= s.top();
//                 s.pop();
//                 s.push(arr[i]);
//             }
//         }
//     }

//     if (s.size() == 2)
//     {
//         profit += s.top();
//         s.pop();
//         profit -= s.top();
//     }

//     return profit;
// }

int main()
{
    // int arr[] = {1, 5, 3, 8, 12};
    // int n = 5;

    //  int arr[] = {30,20,10};
    // int n = 3;

    //  int arr[] = {10, 20, 30};
    // int n = 3;

     int arr[] = {1, 5, 3, 1,2,8};
    int n = 6;

    cout << maxProfit(arr, n) << endl;

    return 0;
}