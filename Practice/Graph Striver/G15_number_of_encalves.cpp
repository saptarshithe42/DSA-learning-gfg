// https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
  
  void dfs(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& vis)
    {
        int n = mat.size();
        int m = mat[0].size();
        
        vis[i][j] = 1;
        
        if(mat[i][j] != 1)
        {
            return;
        }
     
        
        if(i >= 1 && vis[i-1][j] == 0)
            dfs(i-1, j, mat, vis);
        
        if(i <= (n-2) && vis[i+1][j] == 0)
            dfs(i+1, j, mat, vis);
            
        if(j >= 1 && vis[i][j-1] == 0)
            dfs(i, j-1, mat, vis);
            
        if(j <= (m-2) && vis[i][j+1] == 0)
            dfs(i, j+1, mat, vis);
        
    }
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        
        /*
            - same logic as "replace Os with Xs" question. 
            - find out boundary 1s and do dfs, and mark all 1s
              that you can visit.
            - The no. of remaining 1s that cannot be visited is the answer.
        
            - you may also use bfs approach. Solution given here is dfs based.
        */
        int one_count = 0;
        vector<vector<int>> vis (n, vector<int> (m, 0));
        
        
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                    vis[i][j] = -1;
                    
                else if(grid[i][j] == 1)
                    one_count++;
                    
                if((i == 0 || i == (n-1) || j == 0 || j == (m-1)) && grid[i][j] == 1 && vis[i][j] == 0)
                {
                    dfs(i, j, grid, vis);
                    
                }
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(vis[i][j] == 1)
                    count++;
            }
        }
        
        return (one_count - count);
        
        
    }
};