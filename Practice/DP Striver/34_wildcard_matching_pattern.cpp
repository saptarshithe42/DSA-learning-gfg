// https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650

#include<bits/stdc++.h>
using namespace std;


bool f(int n, int m, string& pattern, string& text)
{
    if(n == 0 && m == 0)
        return true;
    
    if(n == 0 && m > 0)
        return false;
    
    if(m == 0 && n > 0)
    {
        if(count(pattern.begin(), pattern.begin() + n, '*') == n)
            return true;
        else 
            return false;
    }
    
    
    if(pattern[n-1] == text[m-1] || pattern[n-1] == '?')
        return f(n-1, m-1, pattern, text);
    
    if(pattern[n-1] == '*')
        return f(n, m-1, pattern, text) || f(n-1, m, pattern, text) ;
    else
        return false;
    

}

// dp sol
bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
    int n = pattern.length(), m = text.length();
    
//     return f(n, m, pattern, text);
    
    bool dp[n+1][m+1];
    
    dp[0][0] = true;
    for(int i = 1; i <= m; i++)
    {
        dp[0][i] = false;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(count(pattern.begin(), pattern.begin() + i, '*') == i )
            dp[i][0] = true;
        else 
            dp[i][0] = false;
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?')
        dp[i][j] = dp[i-1][j-1];
    
    else if(pattern[i-1] == '*')
        dp[i][j] = dp[i][j-1] || dp[i-1][j] ;
        
            else
            {
                dp[i][j] = false;
            }
        }
    }
    
    
    return dp[n][m];
}
