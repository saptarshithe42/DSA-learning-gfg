// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;


// TC same as dijkstra O(E logV) , plus O(n) for backtracking the path using the parent array

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // dijkstra

        // creating the graph
        vector<pair<int, int>> adj[n + 1];  // 1 based graph is there , that's why (n+1)

        for (int i = 0; i < m; i++)
        {
            vector<int> edge = edges[i];

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // standard dijkstra
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 1});
        vector<int> parent(n + 1), dist(n + 1, 1e9);

        dist[1] = 0;

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        while (pq.empty() == false)
        {
            int node = pq.top().second;
            int dis = pq.top().first;

            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (dist[adjNode] > dis + edgeWeight)
                {
                    dist[adjNode] = dist[node] + edgeWeight;
                    pq.push({dist[adjNode], adjNode});

                    parent[adjNode] = node;  // store the vertex you are coming from to keep track of the path
                }
            }
        }

        vector<int> path;

        int node = n;
        // tracing the shortest path
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }

        if (path.size() == 0) // when does not exist 
        {
            path.push_back(-1);
            return path;
        }

        path.push_back(1);

        reverse(path.begin(), path.end());

        return path;
    }
};