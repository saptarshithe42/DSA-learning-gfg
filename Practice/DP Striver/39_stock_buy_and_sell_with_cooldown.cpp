// https://www.codingninjas.com/codestudio/problems/highway-billboards_3125969

#include <bits/stdc++.h> 
using namespace std;

// recursive sol
int f(int ind, int buy, vector<int> &values, int n)
{
    if(ind >= n)
         return 0;
    
    int profit = 0;
    if(buy == 1)
    {
        profit = max(-values[ind] + f(ind+1, 0, values, n),
                    f(ind+1, 1, values, n));
    }
    else
    {
        profit = max(values[ind] + f(ind+2, 1, values, n), 
                    f(ind+1, 0, values, n));
        
    }
    
    
    return profit;
}


// dp sol
int stockProfit(vector<int> &values){
    // Write your code here.
    
//     int ind = 0, buy = 1, n = prices.size();
    
//     return f(ind, buy, prices, n);
    
    int n = values.size();
    int dp[n+2][2];
    
    
    for(int i = 0; i < 2; i++)
    {
        dp[n][i] = 0;
        dp[n+1][i] = 0;
    }
    
    
    
    for(int ind = n-1; ind >= 0; ind--)
    {
        for(int buy = 0; buy < 2; buy++)
        {
            long profit = 0;
            if(buy == 1)
            {
                profit = max(-values[ind] + dp[ind+1][0],                        dp[ind+1][1]);
            }
            else
            {
                profit = max(values[ind] + dp[ind+2][1], 
                            dp[ind+1][0]);
                        
            }

            dp[ind][buy] = profit;
        }
    }
    
    return dp[0][1];
    
}