// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Function to detect cycle in a directed graph.
    bool dfs(int s, vector<int> adj[], vector<int>& vis, vector<int>& pathvis)
    {
        vis[s] = 1;
        pathvis[s] = 1;
        
        for(auto it : adj[s])
        {
            if(vis[it] == 0)
            {
                if(dfs(it, adj, vis, pathvis) == true)
                    return true;
            }
            else if(pathvis[it] == 1)
                return true;
        }
        
        
        pathvis[s] = 0;
        return false;
    }
    
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis (V, 0);
        vector<int> pathvis (V, 0);
        
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                if(dfs(i, adj, vis, pathvis) == true)
                    return true;
            }
        }
        
        return false;
    }
};