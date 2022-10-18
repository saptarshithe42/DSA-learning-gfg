// https://www.codingninjas.com/codestudio/problems/can-you-make_4244510

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

/*
    -keep the lcs same
    -now you need to delete elements in s1, that are 
     not in lcs
    - and insert the elements of s2 into s1, which are
    not in lcs.
 
*/

int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n = str.length(), m = ptr.length();
    
    int lc = lcs(str, ptr);
    
    return ((n - lc) + (m - lc));
    
}
