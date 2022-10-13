// https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

#include <bits/stdc++.h> 
using namespace std;


int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    
    /*
        - using the concept of subset sum equal to k.
        - find total_sum of array
        - apply "subset sum equal to k" dp with total_sum as k
        - in the last row of the dp array, you have the possible 
          sums of first subset.
        - so for those possible sums, find out sum of second subset
          by taking difference with total_sum
        - find the minimum of these differences
        
    */
    
    int total_sum = 0;
    
    for(int i = 0; i < n; i++)
        total_sum += arr[i];
    
    
    int k = total_sum;
    
    bool dp[n+1][k+1];
    
    for(int i = 0; i <= k; i++)
    {
        dp[0][i] = (k == 0) ? true : false;
    }
    
    
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            
            if(j - arr[i-1] >= 0)
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j]; 
            // both included and not included part can give answer
            else
                dp[i][j] =  dp[i-1][j]; // included part does not give answer (k < 0)
            
            /*
                this is the part for 
                if(k < 0)
                    return false;
                -- in recursion
            */
                
                
        }
    }
    
    
    
    int res = INT_MAX;
    
    for(int i = 0; i <= total_sum; i++)
    {
        if(dp[n][i] == true)
        {
            int s1 = i;
            int s2 = total_sum - i;
            
            res = min(res, abs(s1 - s2));
        }
    }
    
    return res;
    
}
