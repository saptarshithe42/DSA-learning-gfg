// https://www.codingninjas.com/codestudio/problems/cost-to-cut-a-chocolate_3208460

#include <bits/stdc++.h> 
using namespace std;

// recursive sol
int f(int i, int j, vector<int>& cuts)
{
    if(i > j) 
        return 0;
    
    int mini = INT_MAX;
    
    for(int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j+1] - cuts[i-1] + f(i, ind-1, cuts) 
            + f(ind+1, j, cuts);
        
        mini = min(mini, cost);
    }
    
    return mini;
    
}

// dp sol
int cost(int n, int c, vector<int> &cuts){
    
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    
    sort(cuts.begin(), cuts.end());
    
//     return f(1, c, cuts);
    
    vector<vector<int>> dp (c+2, vector<int> (c+2, 0));
    
    for(int i = c; i >= 0; i--)
    {
        for(int j = 1; j <= c; j++)
        {
            if(i > j) continue;
            
            int mini = INT_MAX;
    
            for(int ind = i; ind <= j; ind++)
            {
                int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1]
                    + dp[ind+1][j];

                mini = min(mini, cost);
            }

            dp[i][j] = mini;
            
            
        }
    }
    
    return dp[1][c];
    
}