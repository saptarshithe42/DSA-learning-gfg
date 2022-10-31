#include<bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // function to find the ultimate parent of a node
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;

        // O(N+E)
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int node = i;

                int adjNode = it[0];
                int wt = it[1];

                edges.push_back({wt, {node, adjNode}});
            }
        }

        // O(M log M)
        sort(edges.begin(), edges.end());

        DisjointSet ds(V);
        int mstWt = 0;

        // M x 4 x alpha x 2
        for (auto it : edges)
        {
            int wt = it.first;

            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUParent(u) != ds.findUParent(v))
            {
                ds.unionBySize(u, v);
                mstWt += wt;
            }
        }

        return mstWt;
    }
};