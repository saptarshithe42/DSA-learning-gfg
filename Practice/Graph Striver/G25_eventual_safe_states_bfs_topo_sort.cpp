// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
  // reversing the edges
  // doing topological sort
  // the vertices in topological sort are the answer
  // just sort the result array as it asks vertices to be in ascending order
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        vector<int> rev_adj[V];
        
        for(int i = 0; i < V; i++)
        {
            for(auto it : adj[i])
            {
                rev_adj[it].push_back(i);
            }
        }
        
        
        vector<int> res;
	    int indegree[V] = {0};
	    
	    for(int i = 0; i < V; i++)
	    {
	        for(auto it : rev_adj[i])
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
	        
	        for(auto v : rev_adj[u])
	        {
	            indegree[v]--;
	            
	            if(indegree[v] == 0)
	                q.push(v);
	        }
	    }
	    
	    sort(res.begin(), res.end());
	    
        return res;
        
    }
};