#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        // dijkstra
        
        vector<pair<int, int>> adj[n];
        
        for(auto it : roads)
        {
            int u = it[0];
            int v = it[1];
            int time = it[2];
            
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist (n, 1e9);
        vector<int> ways (n, 0);
        
        
        pq.push({0, 0});
        
        dist[0] = 0;
        ways[0] = 1;
        
        int mod = (int) (1e9 + 7);
        
        while(pq.empty() == false)
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int d = it.second;
                
                
                // arriving first time to adjNode
                if(dist[adjNode] > dis + d)
                {
                    dist[adjNode] = dis + d;
                    pq.push({dis + d, adjNode});
                    ways[adjNode] = ways[node];
                }
                // arriving to adjNode from different minimum path so far
                else if(dist[adjNode] == dis + d)
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        

        return ways[n-1] % mod;
        
        
    }
};