// https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MinimumEffort(vector<vector<int>> &heights)
    {

        // dijkstra

        // {diff, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        int delrow[] = {0, 0, 1, -1};
        int delcol[] = {1, -1, 0, 0};

        dist[0][0] = 0;

        pq.push({0, {0, 0}});

        // ElogV -> n x m x 4 x log(n x m) : TC
        while (pq.empty() == false)
        {
            auto it = pq.top();
            pq.pop();

            int diff = it.first;

            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == m - 1)
                return diff;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);

                    if (newEffort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = newEffort;

                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }

        return 0;
    }
};