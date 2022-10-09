// https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349

#include <bits/stdc++.h> 

// recursive solution
int f(int i, int j, vector<vector<int>> &grid)
{
    if(i == 0 && j == 0)
        return grid[0][0];
    
    if(i < 0 || j < 0)
    {
        return INT_MIN;
    }
    
    int up = f(i-1, j, grid);
    int left = f(i, j-1, grid);
    
    if(up < 0)
        up = INT_MAX;
    if(left < 0)
        left = INT_MAX;
    
    return grid[i][j] + min(up, left);
    
}


// tabulation solution
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size();
    int n = grid[0].size();
    
//     return f(m-1, n-1, grid);
    
    
    
    
    int dp[m][n];
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)
                dp[i][j] = grid[0][0];
            
            else
            {
                int up = INT_MAX, left = INT_MAX;
                if(i > 0)
                    up = dp[i-1][j];
                if(j > 0)
                    left = dp[i][j-1];
                
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
        
    }
    
   return dp[m-1][n-1];
   
   
    
}