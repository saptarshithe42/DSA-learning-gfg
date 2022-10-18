// https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293

#include <bits/stdc++.h> 
using namespace std;

int lcs(string s, string t)
{
    //Write your code here
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
    
    return dp[m][n];
}
int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string s1 = s;
    
    reverse(s.begin(), s.end());
    
    string s2 = s;
    
    return lcs(s, s1);
}


/*
    - answer for min deletions to make a string palindrome will 
      also be the same.
*/

int minInsertion(string &str)
{
    // Write your code here.
    
    return (str.length() - longestPalindromeSubsequence(str));
}