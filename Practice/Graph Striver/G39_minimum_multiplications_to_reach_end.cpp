// https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        
       // node numbers are from 0 to (mod - 1)
       // steps increasing by 1 so queue (no need of priority queue)
       // you can take any array element as many times as needed
       
       int mod = 1e5;
       
       queue<pair<int, int>> q; // {vertex, steps_to_reach_vertex}
       
       q.push({start, 0});
       
       vector<int> dist (mod, 1e9);
       
       
       int mul = 1;
       
       while(q.empty() == false)
       {
           int node = q.front().first;
           int steps = q.front().second;
           q.pop();
           
           
           for(auto it : arr)
           {
               int num = (node * it) % mod;
               
               if(steps + 1 < dist[num])
               {
                  dist[num] = steps + 1;
                  
                  if(num == end)
                    return (steps + 1);
                    
                  q.push({num, dist[num]});
               }
                
           }
       }
       
       return -1;
        
        
    }
};
