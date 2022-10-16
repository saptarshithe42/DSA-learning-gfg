// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
    
        // bfs needs to be used here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // {{row, col}, dist_of_nearest_1}

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, 1, -1};

        while (q.empty() == false)
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int d = q.front().second;  
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    dist[nrow][ncol] = d + 1;
                    q.push({{nrow, ncol}, dist[nrow][ncol]});
                }
            }
        }

        return dist;
    }
};