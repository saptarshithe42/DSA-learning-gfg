// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        vector<int> adj[N];
        
        for(int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dist (N, 1e9);
        
        dist[src] = 0;
        
        // normal bfs logic
        queue<int> q;
        q.push(src);
        
        
        while(q.empty() == false)
        {
            int u = q.front(); q.pop();
            
            for(int v : adj[u])
            {
                if(dist[v] > dist[u] + 1)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        
        for(int i = 0; i < N; i++)
        {
            if(dist[i] >= 1e9)
            {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};