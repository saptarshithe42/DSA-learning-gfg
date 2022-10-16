// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        /*
            - We need to BFS graph traversal algorithm, because adjacent 
              fresh oranges are to be rotten level by level. DFS won't work.
            - Firstly, store indexes {i, j} with 0 time instant of the initally
              rotten oranges in the queue. {{i, j}, 0}
              
            - Then do standard BFS algo.
            - Take out each one by one from the queue, check for its
              up, down, left and right and modify fresh oranges to rotten and 
              push them into queue, while increasing time by 1.
              
            - Initially count 1s in the array as freshCount, and reduce this by one
              everytime we rot an orange.
            - Finally, freshCount should become 0, so return the time, 
              otherwise, return -1, as all fresh oranges could not be rotten.
        */
        
        queue<pair<pair<int, int>, int>> q;
        
        vector<vector<int>> vis (n, vector<int> (m, 0));
        
        int freshCount = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
                
                else if(grid[i][j] == 1)
                    freshCount++;
            }
        }
        
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        
        int time = -1;
        
        while(q.empty() == false)
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            bool flag = false;
            for(int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    grid[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t+1});
                    flag = true;
                    freshCount--;
                }
            }
            
            if(flag == true)
            {
                time = q.back().second;
            }
            
        }
        
        
        
        
        return (freshCount == 0) ? time : -1;
    }
};