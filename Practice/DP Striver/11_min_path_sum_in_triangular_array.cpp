// https://www.codingninjas.com/codestudio/problems/triangle_1229398

#include <bits/stdc++.h> 
using namespace std;

// recursive solution
int f(int i, int j, vector<vector<int>>& triangle)
{
    int n = triangle.size(); 
    if(i == n - 1)
    {
        return triangle[i][j];
    }
    
    int down = f(i+1, j, triangle);
    
    int diagonal = INT_MAX;
    
    if(j <= i)
       diagonal = f(i+1, j+1, triangle);
    
    return triangle[i][j] + min(down, diagonal);
        
}


// dp solution
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    
// start from (0, 0) because end point is not fixed.
// starting point (0,0) is fixed.
//     return f(0, 0, triangle);  
    
    int dp[n][n];
    
    for(int i = 0; i < n; i++)
    {
        dp[n-1][i] = triangle[n-1][i];
    }
    
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = i; j >= 0; j--)
        {
            dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    
    
    return dp[0][0];
}