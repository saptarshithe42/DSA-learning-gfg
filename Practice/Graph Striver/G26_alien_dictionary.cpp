// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    
    vector<int>toposort(int V, vector<int> adj[])
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
    
    
    string findOrder(string dict[], int N, int K) {
        /*
            - the first mismatching character between two consecutive strings
              denote that which character is before the other one in ordering,
              which is like a directed edge of a graph.
             
            - now do topological sort to get the order.
        
        
            - ordering will not be possible in two cases :-
                1) if there is cyclic dependency. e.g. : {abc, bca, abb} : a < b < a (first character)
                
                2) if shorter string gets exhausted on comparison, but larger string is 
                   before the shorter one. e.g. : {abcd, abc} : such ordering is wrong,
                   if shorter string is entirely matching, then it should come before
                   the larger one.
        */
        
        vector<int> adj[K];
        
        for(int i = 0; i <= (N-2); i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.length(), s2.length());
            
            for(int ptr = 0; ptr < len; ptr++)
            {
                if(s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }
        
        vector<int> topo = toposort(K, adj);
        string ans = "";
        
        for(auto it : topo)
        {
            ans += char(it + 'a');
        }
        
        return ans;
        
    }
};