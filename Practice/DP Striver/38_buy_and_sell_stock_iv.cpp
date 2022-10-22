// https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698

#include <bits/stdc++.h> 
using namespace std;


int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    int dp[n+1][2][k+1];
    
    for(int i = 0; i < n; i++)
    {
        dp[i][0][0] = 0;
        dp[i][1][0] = 0;
    }
    
    for(int i = 0; i <= k; i++)
    {
        dp[n][0][i] = 0;
        dp[n][1][i] = 0;
    }
    
    
    for(int ind = n-1; ind >= 0; ind--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            for(int cap = 1; cap <= k; cap++)
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
    
    return dp[0][1][k];
    
}
