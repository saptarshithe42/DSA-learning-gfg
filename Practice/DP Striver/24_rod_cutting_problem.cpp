// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284

#include<bits/stdc++.h>
using namespace std;

// recursive sol

int f(int ind, int target, vector<int> &price, vector<int>& lengths)
{
    if(ind == 0)
    {
        if(target % lengths[0] == 0)
        {
            return price[0] * (target / lengths[0]);
        }
        else
            return INT_MIN;
    }
    
    int not_take = f(ind-1, target, price, lengths);
    
    int take = INT_MIN;
    
    if(lengths[ind] <= target)
        take = price[ind] + f(ind, target - lengths[ind], price, lengths);
    
    return max(take, not_take);
}


// dp sol

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<int> lengths(n, 0);
    
    for(int i = 0; i < n; i++)
    {
        lengths[i] = i+1;
    }
    
//     return f(n-1, n, price, lengths);
    
    /*
        -Idea is that consider a length array
        with elements from 1 to N in index 0 to N-1.
        - Now, think in lines similar to knapsack, or 
        target sum from supply of infinite coins problems.
        - So, you need to find ways to have sum N 
        from the elements of lengths array, and instead
        use price[i] whenever considering to take lengths[i],
        and hence maximize the price
    */
    
    
    int dp[n][n+1];
    
    for(int j = 0; j <= n; j++)
    {
        if(j % lengths[0] == 0)
            dp[0][j] = price[0] * (j / lengths[0]);
        else
            dp[0][j] = INT_MIN;
    }
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            int not_take = dp[i-1][j];
            
            int take = INT_MIN;
            
            if(lengths[i] <= j)
                take = price[i] + dp[i][j - lengths[i]];
            
            dp[i][j] = max(take, not_take);
        }
    }
    
    
    return dp[n-1][n];
}
