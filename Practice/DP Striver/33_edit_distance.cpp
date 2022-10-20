// https://www.codingninjas.com/codestudio/problems/edit-distance_630420

#include<bits/stdc++.h>
using namespace std;

// recursive sol
int f(string& s1, string& s2, int n, int m)
{ 
    if(n == 0)
        return m;
    
    if(m == 0)
        return n;
    
    if(s1[n-1] == s2[m-1])
        return f(s1, s2, n-1, m-1);
    
    int insert = 1 + f(s1, s2, n, m-1);
    int del = 1 + f(s1, s2, n-1, m);    
    int replace = 1 + f(s1, s2, n-1, m-1);
    
    return min(insert, min(del, replace));
}

// dp sol
int editDistance(string str1, string str2)
{
    //write you code here
    
    int n = str1.length(), m = str2.length();
    
//     return f(str1, str2, n, m);
    
    int dp[n+1][m+1];
    
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = i; 
    }
    
    for(int i = 0; i <= m; i++)
    {
        dp[0][i] = i; 
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            
            else
            {
                int insert = 1 + dp[i][j-1];
                int del = 1 + dp[i-1][j];    
                int replace = 1 + dp[i-1][j-1];
    
                dp[i][j] = min(insert, min(del, replace));
            }
            
        }
    }
    
    
    
    return dp[n][m];
}