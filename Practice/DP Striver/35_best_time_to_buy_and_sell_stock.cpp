// https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405

#include <bits/stdc++.h> 
using namespace std;


int maximumProfit(vector<int> &prices){
    // Write your code here.
    
    /* for every element, keep track of the minimum
    element on its left. */
    
    int mini = prices[0];
    
    int profit = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        int cost = prices[i] - mini;
        
        profit = max(profit, cost);
        
        mini = min(mini, prices[i]);
    }
    
    return profit;
}