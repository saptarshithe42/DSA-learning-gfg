// https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628

#include <bits/stdc++.h> 
using namespace std;

int mod = (int) (1e9 + 7);

int findWays(vector<int> &num, int k)
{
    // Write your code here.
  int n = num.size();

    vector<vector<int>> dp(n,vector<int>(k+1,0));
    
    if(num[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    
    
    if(num[0] != 0 && num[0] <= k)
        dp[0][num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=k; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken) % mod;
        }
    }
    
    return dp[n-1][k];
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    
    /*
        - Consider two subsets S1 and S2.
        - S1 = (total_sum - S2)
        - So, S1 - S2 = D, becomes : (total_sum - S2) - S2 = D
        
        - So, S2 = (total_sum - D) / 2
        - Thus, we need to find subsets with sum equal to S2, 
          that is, (total_sum - D) / 2
        - Since, all elements are positive integers, (total_sum - D) / 2 should be postive and even
        - Now, "count subsets with given sum" solution.
    */
    
    int total_sum = 0;
    
    for(int x : arr)
    {
        total_sum += x;
    }
    
    if((total_sum - d) < 0 || (total_sum - d) % 2 != 0)
        return false;
    
    return findWays(arr, (total_sum - d)/2);
    
    
}


