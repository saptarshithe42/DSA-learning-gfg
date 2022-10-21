// https://www.codingninjas.com/codestudio/problems/selling-stock_630282

#include<bits/stdc++.h>
using namespace std;


// recursive sol
long f(int ind, int buy, long * values, int n)
{
    if(ind == n)
         return 0;
    
    long profit = 0;
    if(buy == 1)
    {
        profit = max(-values[ind] + f(ind+1, 0, values, n),
                    f(ind+1, 1, values, n));
    }
    else
    {
        profit = max(values[ind] + f(ind+1, 1, values, n), 
                    f(ind+1, 0, values, n));
        
    }
    
    
    return profit;
}

// dp sol
long getMaximumProfit(long *values, int n)
{
    /* // without dp sol
    long profit = 0;
    for(int i = 1; i < n; i++)
    {
        long diff = (values[i] - values[i-1]);
        profit += (diff > 0) ? diff : 0;
    }
    return profit; 
    */
    
//     return f(0, 1, values, n);
    
    long dp[n+1][2];
    
    for(int i = 0; i < 2; i++)
    {
        dp[n][i] = 0;
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
                profit = max(values[ind] + dp[ind+1][1], 
                            dp[ind+1][0]);
                        
            }

            dp[ind][buy] = profit;
        }
    }
    
    return dp[0][1];
}