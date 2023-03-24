#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        int timer = 0;
        
        
        void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], int tin[],
        int low[], vector<int>& mark)
        {
            vis[node] = 1;
            
            tin[node] = low[node] = timer;
            timer++;
            
            int child = 0;
            for(auto it : adj[node])
            {
                if(it == parent)
                    continue;
                    
                if(!vis[it])
                {
                    dfs(it, node, vis, adj, tin, low, mark);
                    
                    low[node] = min(low[node], low[it]);
                    
                    // check for articulation point
                    if(low[it] >= tin[node] && parent != -1)
                    {
                        mark[node] = 1;
                    }
                    child++;
                }
                else
                {
                    low[node] = min(low[node], tin[it]);
                }
            }
            
            if(child > 1 && parent == -1)
                mark[node] = 1;
        }
    
    
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        
        
        vector<int> vis (n, 0);
        
        int tin[n]; // store time of insertion during DFS
        int low[n]; // minimum time of insertion of all adjacnet nodes apart from parent and visited nodes
        
        vector<int> mark(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                dfs(i, -1  ,vis, adj, tin, low, mark);
            }
        }
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++)
        {
            if(mark[i] == 1) {
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0)
        {
            return {-1};
        }
        
        
        return ans;
        
        
    }
};