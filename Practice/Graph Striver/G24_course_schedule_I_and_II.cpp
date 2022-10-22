#include<bits/stdc++.h>
using namespace std;

// Application of Topological Sorting

// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1

bool isPossible(int V, vector<pair<int, int> >& prerequisites) {
	    // using topological sort
	    // if cycle is found, that is, cyclic dependency, then not possible.
	    // if cycle not found, then it is possible to finish all tasks.
	    vector<int> adj[V];
	    
	    for(auto it : prerequisites)
	    {
	        adj[it.second].push_back(it.first);
	    }
	    
	    
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
	    
	    return (res.size() == V);
	}


// https://practice.geeksforgeeks.org/problems/course-schedule/1

vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adj[V];
	    
	    for(auto it : prerequisites)
	    {
	        adj[it[1]].push_back(it[0]);
	    }
	    
	    
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
	    
	    if(res.size() == V)
	        return res;
	   
	   return {};
    }