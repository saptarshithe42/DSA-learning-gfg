// https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980

#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    
    /*
       - find out the total sum of the array
       - since, the array contains "integers", we can draw 
       following conclusions :-
       
       1. If the total sum is odd, then it cannot be divided
           equally into 2 parts. So, return false in that case.
           
       2. If the total sum is even, then it is possible to 
           partition into 2 equal parts. 
           
       Proceed in case of even total sum as follows :-
       
       - find if a subset with sum of elements equal to 
           (total sum) / 2 is present or not.
       - If not present return false;
       - If present return true,  because remanining part will also 
           have sum as (total sum) / 2.
        
       - Use the solution of question - subset sum equal to k
    
    */
    
    if(n == 1)
        return false;
    
    int sum = 0;
    
    for(auto x : arr)
        sum += x;
    
    if(sum % 2 != 0)
        return false;
    
    int k = sum / 2;
    
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
    
    return dp[n][k];
    
}
