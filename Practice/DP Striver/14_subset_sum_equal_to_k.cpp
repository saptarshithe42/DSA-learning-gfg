// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

#include <bits/stdc++.h> 
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    
    
    // recursive solution
    
    /*
        main idea : for every element, you either include it in 
        subset or not include it.
    */
    
    /*
    if(n == 0)
        return (k == 0) ? true : false;
    
    if(k == 0)
        return true;
    
//     if(k < 0)
//         return false;
    
    int included = subsetSumToK(n-1, k - arr[n-1], arr);
    int not_included = subsetSumToK(n-1, k, arr);
    
    return (included || not_included);
    
    */
    
    
    // dp solution
    
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
            
            // both included and not included part can give answer
            if(j - arr[i-1] >= 0)
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j]; 
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
    
    return dp[n][k];
    
}