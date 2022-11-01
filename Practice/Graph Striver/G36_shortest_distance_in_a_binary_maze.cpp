// https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
        int n = grid.size();
        int m = grid[0].size();
        
        // {distance_from_source, {row, col}}
        queue<pair<int, pair<int, int>>> q;
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        
        while(q.empty() == false)
        {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dis = q.front().first;
            
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1)
                {
                    if(dist[nrow][ncol] > dis + 1)
                    {
                        dist[nrow][ncol] = dis + 1;
                        q.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        
        int res = dist[destination.first][destination.second];
        
        return (res == 1e9) ? -1 : res;
    }
};