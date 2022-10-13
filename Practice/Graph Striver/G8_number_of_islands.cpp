// https://practice.geeksforgeeks.org/batch/cip-1/track/P100-Graph/problem/find-the-number-of-islands

#include<bits/stdc++.h>
using namespace std;

class solution{
void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        
        q.push({row, col});
        vis[row][col] = 1;
        
        while(q.empty() == false)
        {
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            
            // traversing all the 8 neighbours of grid[row][col]
            
            for(int delrow = -1; delrow <= 1; delrow++)
            {
                for(int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                    && grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0)
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        
        vector<vector<int>> vis (n, vector<int> (m, 0));
        
        int count = 0;
        
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(vis[row][col] == 0 && grid[row][col] == '1')
                {
                    count++;
                    
                    bfs(row, col, grid, vis);
                }
            }
        }
        
        return count;
        
    }
};