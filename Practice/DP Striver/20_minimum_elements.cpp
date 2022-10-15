// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091

#include <bits/stdc++.h> 
using namespace std;

// recursive sol
int f(vector<int> &num, int ind, int x)
{

    
    if(ind == 0)
    {
        if(x % num[0] == 0)
        {
            return (x / num[0]);
        }
        else 
            return 1e9;
    }
    
    int not_take = f(num, ind-1, x);
    
    int take = INT_MAX;
    
    if(num[ind] <= x)
        take = 1 + f(num, ind, x - num[ind]);
        // stay at the same index because infinite supply of each coin
    
    return min(take, not_take);
}


// dp sol

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    
//     int ans = f(num, n-1, x);
    
//     ans = (ans >= 1e9) ? -1 : ans;
    
//     return ans;
    
    int dp[n][x+1];
    
    for(int i = 0; i <= x; i++)
    {
        dp[0][i] = (i % num[0] == 0) ? (i / num[0]) : 1e9; 
        
    }
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= x; j++)
        {
            int not_take = dp[i-1][j];
            
            int take = INT_MAX;
            
            if(num[i] <= j)
                take = 1 + dp[i][j - num[i]];
            
            dp[i][j] = min(take, not_take);
            
            
        }
    }
    dp[n-1][x] = (dp[n-1][x] >= 1e9) ? -1 : dp[n-1][x];
    
    return dp[n-1][x];
    
}