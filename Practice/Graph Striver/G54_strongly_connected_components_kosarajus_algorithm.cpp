// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	void dfs(int s, vector<int>& vis, stack<int>& st ,vector<vector<int>>& adj)
	{
	    vis[s] = 1;
	    
	    for(auto it : adj[s])
	    {
	        if(vis[it] == 0)
	        {
	            dfs(it, vis, st, adj);
	        }
	    }
	    
	    st.push(s);
	}
	
	void dfs(int s, vector<int>& vis, vector<int> adj[])
	{
	    vis[s] = 1;
	    
	    for(auto it : adj[s])
	    {
	        if(vis[it] == 0)
	        {
	            dfs(it, vis, adj);
	        }
	    }
	}
	  
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        
        vector<int> vis(V, 0);
        
        stack<int> s;
        
        // get elements in decreasing order of finish times
        // O(V+E)
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i, vis, s, adj);
            }
        }
        
        vector<int> adjT[V];
        
        // reverse the edges in the graph
        // O(V+E)
        for(int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for(auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        
        // do dfs 
        
        int scc = 0;
        // O(V+E)
        while(!s.empty())
        {
            int node = s.top(); s.pop();
            
            if(!vis[node])
            {
                scc++;
                dfs(node, vis, adjT);
            }
        }
        
        return scc;
        
    }
};