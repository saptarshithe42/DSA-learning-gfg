// https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493

#include <bits/stdc++.h> 
using namespace std;


string shortestSupersequence(string s, string t)
{
	// Write your code here.
    int m = s.length();
    int n = t.length();
    
//     return f(m-1, n-1, s, t);
    
    int dp[m+1][n+1];
    
    for(int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }
    
    for(int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    // length of shortest common supersequence
    int len = m + n - dp[m][n];
    

    string res = "";
    
    int i = m, j = n;
   
    
    while(i > 0 && j > 0)
    {
        if(s[i-1] == t[j-1])
        {
            res += s[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            res += s[i-1];
            i--;
        }
        else
        {
            res += t[j-1];
            j--; 
        }
    }
    
    while(i > 0)
    {
        res += s[i-1];
        i--;
    }
    
    while(j > 0)
    {
        res += t[j-1];
        j--;
    }
    
    reverse(res.begin(), res.end());
    
    return res;
}