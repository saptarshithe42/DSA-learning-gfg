// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

#include<bits/stdc++.h>
using namespace std;


class Solution {
    private:
    void dfs(int s, vector<int>& vis, vector<pair<int, int>> adj[], stack<int>& st)
    {
        vis[s] = 1;
        
        for(auto it : adj[s])
        {
            if(vis[it.first] == 0)
                dfs(it.first, vis, adj, st);
        }
        
        st.push(s);
        
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){

        vector<pair<int, int>> adj[N];
        
        for(int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v ,w});
        }
        
        
        // step 1 - find the topo sort
        stack<int> st;
        vector<int> vis (N, 0);
        // dfs - O(N+E)
        for(int i = 0; i < N; i++)
        {
            if(vis[i] == 0)
                dfs(i, vis, adj, st);
        }
        
        // step 2 - distance array initialised with 0 for given source, and INF for others
        
        vector<int> dist (N, 1e9);
        
        // here source is 0
        dist[0] = 0;
        
        // O(N + M)
        while(st.empty() == false)
        {
            int u = st.top(); st.pop();
            
            for(auto it : adj[u])
            {
                int v = it.first;
                int w = it.second;
                
                dist[v] = min(dist[v], dist[u] + w);
            }
            
        }
        
        
        for(int& it : dist)
        {
            if(it >= 1e9)
                it = -1;
        }
      
        return dist;
    }
};