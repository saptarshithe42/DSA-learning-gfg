#include<bits/stdc++.h>
using namespace std;


/*
    - main advantage over Dijkstra algorithm, is that, Bellman Ford algorithm
    works for graphs with negative edges / cycles as well.
*/


class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // TC : O(VE)
        
        vector<int> dist (V, 1e8);
        dist[S] = 0;
        // relax all edges (V-1) times

        
        for(int i = 0; i < V-1; i++)
        {
            for(auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        /*
        if you can relax any edge, even after (V-1) relaxations, 
        then graph has negative cycle.
        */
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            if(dist[v] > dist[u] + w)
            {
                return {-1};
            }
        }
        
        
        
        
        return dist;
        
        
    }
};
