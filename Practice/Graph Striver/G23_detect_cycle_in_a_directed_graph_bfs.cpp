#include<bits/stdc++.h>
using namespace std;


class Solution
{
     public:
    // Function to detect cycle in a directed graph.
    // using topological sort , bfs
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
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
	    
	    return (res.size() != V);
        
        
    }
};