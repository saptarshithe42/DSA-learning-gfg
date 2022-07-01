#include <iostream>
using namespace std;

// time complexity : theta(n^2)
// aux sp : theta(n)
int minJumps(int arr[], int n)
{
    int dp[n];
    dp[0] = 0;

    // for(int i = 1; i < n; i++)
    // {
    //     dp[i] = INT_MAX;
    // }
    
    for(int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
        for(int j = 0; j < i; j++)
        {
            if((dp[j] != INT_MAX) && (arr[j] + j >= i))
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }


    return dp[n-1];
}

int main()
{
    // int arr[] = {3, 4, 2, 1, 2, 1};
    // int n = 6;

    int arr[] = {4, 1, 5, 3, 1, 3, 2, 1, 8};
    int n = 9;

    cout << minJumps(arr, n);

    return 0;
}