// https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1

#include<bits/stdc++.h>
using namespace std;

// dijkstra application

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        
        
        vector<pair<int, int>> adj[n];
        
        for(int i = 0; i < flights.size(); i++)
        {
            auto it = flights[i];
            
            int u = it[0];
            int v = it[1];
            int price = it[2];
            
            adj[u].push_back({v, price}); 
        }
        
        
        // {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;
        
        vector<int> dist (n, 1e9);
        
        q.push({0, {src, 0}});
        dist[src] = 0;
        
        while(q.empty() == false)
        {
            auto it = q.front();
            
            int node = it.second.first;
            int stops = it.first;
            int cost = it.second.second;
            q.pop();
            
            if(stops > K)
                continue;
                
            for(auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edW = iter.second;
                
                if(dist[adjNode] > cost + edW && stops <= K)
                {
                    dist[adjNode] = edW + cost;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
            
            
            
        }
        
        
        return (dist[dst] == 1e9) ? -1 : dist[dst];
        
    }
};