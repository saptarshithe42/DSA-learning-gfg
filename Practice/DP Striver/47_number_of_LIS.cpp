// https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627

#include <bits/stdc++.h> 
using namespace std;

int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    int maxi = 1;
    vector<int> dp(n,1), count(n,1);
  
    int ind;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                // inherit
                count[i] = count[j];
            }
            else if(arr[j] < arr[i] && dp[i] == dp[j] + 1)
            {
                // increase the length
                count[i] += count[j];
            }
          
        }
        if(maxi < dp[i])
        {
            maxi = dp[i];
        }
    }
 
    int res = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(dp[i] == maxi)
        {
            res += count[i];
        }
    }
   
    return res;
        
}