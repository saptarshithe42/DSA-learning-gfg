// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <bits/stdc++.h>
using namespace std;


/*
    - Dijkstra's algo does not work for graphs with negative weights or negative weight
    cycles, because it falls in an infinite loop.
    - It is a greedy approach.
*/

class Solution
{

public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    // TC : O(E logV) , E - total no. of edges, V - no. of nodes
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, 1e9);

        dist[S] = 0;

        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // storing {distance_from_source_in_current_path, vertex} as pair
        pq.push({0, S});

        while (pq.empty() == false)
        {
            int node = pq.top().second;
            int dis = pq.top().first;

            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWeight = it[1];

                // relaxation of edges
                if (dist[adjNode] > dis + edgeWeight)
                {
                    dist[adjNode] = dis + edgeWeight;

                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};