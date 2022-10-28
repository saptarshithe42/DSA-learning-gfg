// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include<bits/stdc++.h>
using namespace std;

/*
    - to get the edges that are part of MST, store this type of pair 
      in the min heap :-

      {wt, {node, parent}}

      for first node (0), use -1 in place of parent and don't include it;
*/

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis (V, 0);
        
        // {wt, node}
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 0});
        
        int sum = 0;
        
        while(pq.empty() == false)
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            if(vis[node] == 1)
                continue;
                
                
            // added to MST
            vis[node] = 1;
            sum += wt;
            
            for(auto it : adj[node])
            {
                int adjNode = it[0];
                int edW = it[1];
                
                if(vis[adjNode] == 0)
                {
                    pq.push({edW, adjNode});
                }
            }
        }

        return sum;
        
    }
};