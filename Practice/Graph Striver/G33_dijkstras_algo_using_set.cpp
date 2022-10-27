// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include<bits/stdc++.h>
using namespace std;

/*
    using set gives some advantage in certain cases, however not much difference
    than using priority queue. In some cases, set helps to avoid iteration with
    the same vertex but different(and greater) distance from the source, 
    even after getting the minimum distance for that vertex.

    For e.g. : {8, 5} entered in the queue, also {10, 5} is present and is below it
    for some graph (suppose), so if we use set, we can delete the {10, 5} pair as
    we already of got distance from source as 8 for vertex 5 which is a better choice
    and hence useless to do iterations with {10, 5}.
*/

class Solution{
public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, 1e9);
        
        dist[S] = 0;
        
        set<pair<int,int>> s;
        
        // storing {distance_from_source_in_current_path, vertex} as pair
        s.insert({0, S});
        
        while(s.empty() == false)
        {
            int node  = s.begin()->second;
            int dis = s.begin()->first;
            
            s.erase(s.begin());
            
            for(auto it : adj[node])
            {
                int  adjNode = it[0];
                int edgeWeight = it[1];
                
                // relaxation of edges
                if(dist[adjNode] > dis + edgeWeight)
                {
                    
                    if(dist[adjNode] != 1e9) 
                    {
                        s.erase({dist[adjNode], adjNode});
                    }
                    
                    dist[adjNode] = dis + edgeWeight;
                    
                    s.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        
        return dist;
    }
};