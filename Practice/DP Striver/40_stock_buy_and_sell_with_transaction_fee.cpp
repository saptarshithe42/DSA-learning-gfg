// https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974

#include <bits/stdc++.h> 
using namespace std;

// recursive sol
int f(int ind, int buy, vector<int> &values, int n, int fee)
{
    if(ind >= n)
         return 0;
    
    int profit = 0;
    if(buy == 1)
    {
        profit = max(-values[ind] - fee + f(ind+1, 0, values, n, fee),
                    f(ind+1, 1, values, n, fee));
    }
    else
    {
        profit = max(values[ind] + f(ind+1, 1, values, n, fee), 
                    f(ind+1, 0, values, n, fee));
        
    }
    
    
    return profit;
}

// dp sol

int maximumProfit(int n, int fee, vector<int> &values) {
    // Write your code here.
    
//     return f(0, 1, prices, n, fee);
    
     int dp[n+1][2];
    
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
                profit = max(-values[ind] - fee + dp[ind+1][0],                        dp[ind+1][1]);
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
