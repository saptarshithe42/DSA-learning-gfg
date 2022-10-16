// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

#include <bits/stdc++.h> 
using namespace std;

// recursive solution (not correct for some zero present in array cases, see dp solution directly.)
/*
int f(int n, int k, vector<int>& arr)
{
    if(k == 0)
        return 1;
    
    if(n == 0)
        return (k == 0) ? 1 : 0;
    
    if(k < 0)
        return 0;
    
    int included = 0;
    
    if(k - arr[n-1] >= 0)
        included = f(n-1, k - arr[n-1], arr);
    
    int not_included = f(n-1, k, arr);
    
    return (included + not_included);
}
*/


// dp solution
int findWays(vector<int> &num, int k)
{
    // Write your code here.
  int n = num.size();

    vector<vector<int>> dp(n,vector<int>(k+1,0));
    
    /*
        - modifications made for cases like {0,0,1}, and
        sum = 1, answer should be 4 ({1}, {0,1}, {0,1}, {0,0,1}).
    */
    
    if(num[0] == 0)
        dp[0][0] = 2; // by taking num[0] and not taking it
    else
        dp[0][0] = 1; // by not taking num[0] as num[0] != 0
    
    
    if(num[0] != 0 && num[0] <= k)
        dp[0][num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=k; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= notTaken + taken;
        }
    }
    
    return dp[n-1][k];
}