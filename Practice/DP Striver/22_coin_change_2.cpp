// https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471

#include<iostream>
using namespace std;

// recursive sol
int f(int *arr, int ind, int value)
{
//     if(value == 0)
//         return 1;
    
    if(ind == 0)
    {
        if(value % arr[0] == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    
    int not_take = f(arr, ind-1, value);
    
    int take = 0;
    
    if(arr[ind] <= value)
        take = f(arr, ind, value - arr[ind]);
        // stay at the same index because infinite supply of each coin
    
    return (take + not_take);
}

// dp sol

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
//     return f(denominations, n-1, value);

    int k = value;
    long dp[n][k+1];
    
    
    
    for(int i = 0; i <= k; i++)
    {
        dp[0][i] = (i % denominations[0] == 0) ? 1 : 0;
    }
    
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            long not_take = dp[i-1][j];
            
            long take = 0;
            
            if(denominations[i] <= j)
                take = dp[i][j - denominations[i]];
            
            dp[i][j] = take + not_take;
        }
    }
    
    
    return dp[n-1][k];
}