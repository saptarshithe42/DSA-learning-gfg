// https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470

#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
    
//     if(m == 1)
//     {
//         return 1;
//     }
//     if (n == 1)
//     {
//         return 1;
//     }
    
//     return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    
    int dp[m+1][n+1];
    
    for(int i = 0; i <= m; i++)
    {
        dp[i][1] = 1;
    }
    for(int i = 0; i <= n; i++)
    {
        dp[1][i] = 1;
    }
    
    for(int i = 2; i <= m; i++)
    {
        for(int j = 2; j <= n; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
        
    return dp[m][n];
}