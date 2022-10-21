#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int s, vector<int> adj[], vector<int>& vis, stack<int>& st)
	{
	    vis[s] = 1;
	    
	    for(auto it : adj[s])
	    {
	        if(vis[it] == 0)
	            dfs(it, adj, vis, st);
	    }
	    
	    st.push(s);
	}
	
	vector<int> bfs(int V, vector<int> adj[])
	{
	    vector<int> res;
	    int indegree[V] = {0};
	    
	    for(int i = 0; i < V; i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int i = 0; i < V; i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(q.empty() == false)
	    {
	        int u = q.front();
	        q.pop();
	        
	        res.push_back(u);
	        
	        for(auto v : adj[u])
	        {
	            indegree[v]--;
	            
	            if(indegree[v] == 0)
	                q.push(v);
	        }
	    }
	    
	    return res;
	}
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> res;
	    vector<int> vis (V, 0);
	    
	    /*
	    stack<int> s;
	    
	    for(int i = 0; i < V; i++)
	    {
	        if(vis[i] == 0)
	        {
	            dfs(i, adj, vis, s);
	        }
	    }
	    
	    while(s.empty() == false)
	    {
	        res.push_back(s.top());
	        s.pop();
	    }
	    
	    */
	    
	    res = bfs(V, adj);
	    
	    return res;
	}
};