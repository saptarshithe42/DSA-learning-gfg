// https://practice.geeksforgeeks.org/problems/bipartite-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int s, vector<int> adj[], vector<int> &color, int col)
    {
        color[s] = col;

        for (auto it : adj[s])
        {
            if (color[it] == -1)
            {
                if (dfs(it, adj, color, !col) == false)
                    return false;
            }
            else if (color[it] == col)
                return false;
        }

        return true;
    }

    bool bfs(int s, vector<int> adj[], vector<int> &color)
    {

        queue<int> q;
        q.push(s);

        color[s] = 0;
        while (q.empty() == false)
        {
            int node = q.front();

            q.pop();

            for (auto it : adj[node])
            {
                // if adjacent node is not yet color, give opposite color
                if (color[it] == -1)
                {
                    q.push(it);
                    color[it] = !color[node];
                }
                // if adjacent node has same color, then not bipartite
                else if (color[it] == color[node])
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here

        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                // if(dfs(i, adj, color, 0) == false)
                //     return false;

                if (bfs(i, adj, color) == false)
                    return false;
            }
        }

        return true;
    }
};