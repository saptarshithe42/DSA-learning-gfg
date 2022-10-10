// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

// we need to go from first row to last row
// starting and ending location not fixed

#include <bits/stdc++.h> 
using namespace std;

// recursive solution
int f(int i, int j, vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    if(i == n-1)
    {
        return matrix[n-1][j];
    }
    
    int down = f(i+1, j, matrix);
    int diag_left = INT_MIN, diag_right = INT_MIN;
    
    if(j != 0)
        diag_left = f(i+1, j-1, matrix);
    
    if(j != m-1)
        diag_right = f(i+1, j+1, matrix);
    
    return matrix[i][j] + max(down, max(diag_left, diag_right));
    
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    
    int n = matrix.size();
    int m = matrix[0].size();
    
//     int res = INT_MIN;
    
//     for(int i = 0; i < m; i++)
//     {
//         res = max(res, f(0, i, matrix));
//     }
    
//     return res;
    
    int dp[n][m];
    
    for(int i = 0; i < m; i++)
    {
        dp[n-1][i] = matrix[n-1][i];
    }
    
    
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = m-1; j >= 0; j--)
        {
            int down = dp[i+1][j];
            
            int diag_left = INT_MIN, diag_right = INT_MIN;
            
            if(j != 0)
                diag_left = dp[i+1][j-1];
            
            if(j != m-1)
                diag_right = dp[i+1][j+1];
            
            dp[i][j] = matrix[i][j] + max(down, max(diag_left, diag_right));
            
        }
    }
    
    
    int res = INT_MIN;
    
    for(int i = 0; i < m; i++)
    {
        res = max(res, dp[0][i]);
    }
    
    return res;
}