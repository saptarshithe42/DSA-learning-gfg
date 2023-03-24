// https://leetcode.com/problems/critical-connections-in-a-network/

#include<bits/stdc++.h>
using namespace std;



class Solution {

private:
    int timer = 1;

    void dfs(int node, int parent, vector<int>& vis ,vector<int> adj[],
    int tin[], int low[], vector<vector<int>>& bridges)
    {
        vis[node] = 1;

        tin[node] = low[node] = timer;
        timer++;

        for(auto it : adj[node])
        {
            if(it == parent)
                continue;

            if(vis[it] == 0)
            {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);

                // check for bridge
                if(low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }


public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<int> adj[n];

        for(auto it : connections)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis (n, 0);

        int tin[n]; // store time of insertion during DFS
        int low[n]; // minimum time of insertion of all adjacent nodes apart from parent

        vector<vector<int>> bridges;

        dfs(0, -1, vis, adj, tin, low, bridges);

        return bridges;
        
    }
};