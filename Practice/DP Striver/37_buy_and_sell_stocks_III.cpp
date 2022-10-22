// https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012

#include <bits/stdc++.h> 
using namespace std;

// recursive sol

int f(int ind, int buy, int cap, int n, vector<int>& prices)
{
    if(cap == 0)
        return 0;
    
    if(ind == n)
    {
        return 0;
    }
    
    int profit = 0;
    
    if(buy == 1)
    {
        profit = max(-prices[ind] + f(ind+1, 0, cap, n, prices), f(ind+1, 1, cap, n, prices));
    }
    else
    {
        profit = max(prices[ind] + f(ind+1, 1, cap-1, n, prices), f(ind+1, 0, cap, n, prices));
    }
    
    
    return profit;
}


// dp sol
int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    
//     int cap = 2, ind = 0, buy = 1;
//     return f(ind, buy, cap, n, prices);
    
    int dp[n+1][2][3];
    
    for(int i = 0; i < n; i++)
    {
        dp[i][0][0] = 0;
        dp[i][1][0] = 0;
    }
    
    for(int i = 0; i < 3; i++)
    {
        dp[n][0][i] = 0;
        dp[n][1][i] = 0;
    }
    
    
    for(int ind = n-1; ind >= 0; ind--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            for(int cap = 1; cap <= 2; cap++)
            {
                int profit = 0;
                if(buy == 1)
                {
                    profit = max(-prices[ind]+dp[ind+1][0][cap], dp[ind+1][1][cap]);
                }
                else
                {
                    profit = max(prices[ind]+dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                }
                
                dp[ind][buy][cap] = profit;
            }
        }
    }
    
    return dp[0][1][2];
    
    
}