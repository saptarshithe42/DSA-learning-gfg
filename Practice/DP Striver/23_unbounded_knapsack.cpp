// https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029

#include <bits/stdc++.h> 
using namespace std;

// recursive sol
int f(int ind, int w, vector<int> &profit, vector<int> &weight)
{
    if(ind == 0)
    {
        if(weight[0] <= w)
        {
            return (profit[0]) * (w / weight[0]);
        }
        else
            return 0;
    }
    
    
    int not_take = f(ind-1, w, profit, weight);
    
    int take = INT_MIN;
    
    if(weight[ind] <= w)
        take = profit[ind] + f(ind, w - weight[ind], profit, weight);
    
    
    return max(take, not_take);
}

// dp sol
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    
//     return f(n-1, w, profit, weight);
    
    int dp[n][w+1];
    
    for(int i = 0; i <= w; i++)
    {
        if(weight[0] <= i)
        {
            dp[0][i] = (profit[0]) * (i / weight[0]);
        }
        else
            dp[0][i] = 0;
    }
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            int not_take = dp[i-1][j];    
            int take = INT_MIN;
    
        if(weight[i] <= j)
            take = profit[i] + dp[i][j- weight[i]];
    
    
        dp[i][j] = max(take, not_take);
        }
    }
    
    
    return dp[n-1][w];
}
