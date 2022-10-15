// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[], int s, bool vis[], int parent)
    {
        vis[s] = true;

        for (int u : adj[s])
        {
            if (vis[u] == false)
            {
                if (dfs(adj, u, vis, s) == true)
                    return true;
            }

            else if (u != parent)
                return true;
        }

        return false;
    }

    bool bfs(vector<int> adj[], int s, bool vis[], int parent)
    {
        vis[s] = true;

        queue<pair<int, int>> q;

        q.push({s, parent});

        while (q.empty() == false)
        {
            int u = q.front().first;
            int p = q.front().second;
            q.pop();

            for (int v : adj[u])
            {
                if (vis[v] == false)
                {
                    q.push({v, u});
                    vis[v] = true;
                }
                else if (v != p)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here

        bool vis[V] = {false};

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == false)
            {
                // if(dfs(adj, i, vis, -1) == true)
                //     return true;

                if (bfs(adj, i, vis, -1) == true)
                    return true;
            }
        }

        return false;
    }
};