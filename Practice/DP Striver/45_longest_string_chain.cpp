// https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111

#include <bits/stdc++.h> 
using namespace std;


bool compare(string& s1, string& s2)
{
    int n = s1.length(), m = s2.length();
    
    if(n != (m+1))
        return false;
    
    int i = 0, j = 0;
    
    while(i < n)
    {
        if(j< m && s1[i] == s2[j])
        {
            i++; j++;
        }
        else
            i++;
    }
    
    if(i == n && j == m)
           return true;
    
    return false;
    
}


bool comp(string& s1, string& s2)
{

    return s1.length() < s2.length();
}

int longestStrChain(vector<string> &arr)
{
    /*
        - application of LIS approach
        - sort strings by length
        - then do lis like approach for strings differing 
          by one length (see the comparison function)
        - here it says : sequence (so it considers subsets, not subsequences)
    */
    
    
    sort(arr.begin(), arr.end(), comp);
    
    int n = arr.size();
    
    vector<int> dp (n, 1);
    int maxi = 1;
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(compare(arr[i], arr[j]) == true && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        
        if(dp[i] > maxi)
        {
            maxi = dp[i];
        }
    }
    
    
    
    return maxi;
}