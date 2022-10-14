// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

#include <bits/stdc++.h> 
using namespace std;
// recursive sol
int f(vector<int>& weight, vector<int>& value, int ind, int w) 
{
    if(w == 0)
    {
        return 0;
    }
    
    if(ind == 0)
    {
        if(weight[0] <= w)
            return value[0];
        else
            return 0;
    }
    
    int take = INT_MIN;
    
    if(weight[ind] <= w)
        take = value[ind] + f(weight, value, ind-1, w - weight[ind]);
    
    int not_take = f(weight, value, ind-1, w);
    
    return max(take, not_take);
}


// dp sol

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    
//     return f(weight, value, n-1, maxWeight);
    
    int w = maxWeight;
    
    int dp[n][w+1];
    
    for(int i = 0; i <= w; i++)
    {
        dp[0][i] = (weight[0] <= i) ? value[0] : 0;
    }
    
    for(int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            int not_take = dp[i-1][j];
            
            int take = INT_MIN;
            
            if(weight[i] <= j)
                take = value[i] + dp[i-1][j - weight[i]];
            
            dp[i][j] = max(take, not_take);
        }
    }
    
    return dp[n-1][w];
    
}