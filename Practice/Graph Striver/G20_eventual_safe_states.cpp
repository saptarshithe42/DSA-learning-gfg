// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool dfs(int s, vector<int> adj[], vector<int>& vis, vector<int>& pathvis, vector<int>& check)
    {
        vis[s] = 1;
        pathvis[s] = 1;
        check[s] = 0;
        
        for(auto it : adj[s])
        {
            if(vis[it] == 0)
            {
                // leads to a cycle
                if(dfs(it, adj, vis, pathvis, check) == true)
                {
                    check[it] = 0;
                    return true;
                }
            }
            // part of a cycle
            else if(pathvis[it] == 1)
            {
                check[it] = 0;
                return true;
            }
        }
        
        check[s] = 1;
        pathvis[s] = 0;
        return false;
    }

    /*
        Nodes that lead to a cycle or are part of a cycle
        cannot be safe nodes. Rest others are safe nodes.
    */
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis (V, 0);
        vector<int> pathvis (V, 0);
        vector<int> check (V, 0);
        vector<int> safeNodes;
        
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i, adj, vis, pathvis, check);
            }
        }
        
        for(int i = 0; i < V; i++)
        {
            if(check[i] == 1)
                safeNodes.push_back(i);
        }
        
        
        return safeNodes;
        
    }
};