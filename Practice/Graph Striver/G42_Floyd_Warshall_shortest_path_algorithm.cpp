// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#include<bits/stdc++.h>
using namespace std;

/*
    - Floyd Warshall Algorithm
    - This is a multi-source shortest path algorithm.
    - We need find shortest path from every vertex to every other vertex.
    - Helps to detect negative weight cycles as well.
    - Go via every vertex or node.
    - Dynamic programming approach.
    - For undirected graph, make the edges doubly connected and of same weight,
      that is, make 0 -- 1 ==> 0 <- 1 and 0 -> 1, then apply this algo.

    - d[i][j] ==> min(d[i][k] + d[k][j]) [via k]

    - it is quite a brute force as it tries out all possibilities.
    - if(cost[i][i] < 0) , then negative cycle exists. Ideally cost[i][i] == 0.
*/

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){

	    int n = matrix.size();
	    
	     for(int i = 0; i < n; i++)
	        {
	            for(int j = 0; j < n; j++)
	            {
	                if(matrix[i][j] == -1)
	                    matrix[i][j] = 1e9;
	                
	                
	            }
	            matrix[i][i] = 0;
	        }
	    
	    
	    // TC : O(n^3)
	    
	    for(int via = 0; via < n; via++)
	    {
	        for(int i = 0; i < n; i++)
	        {
	            for(int j = 0; j < n; j++)
	            {
	                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
	            }
	        }
	    }
	    
	    for(int i = 0; i < n; i++)
	        {
	            for(int j = 0; j < n; j++)
	            {
	                if(matrix[i][j] >= 1e9)
	                    matrix[i][j] = -1;
	            }
	        }
	}
};