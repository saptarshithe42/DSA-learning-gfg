// https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879

#include<bits/stdc++.h>
using namespace std;
// recursive sol
int f(int ind1, int ind2, string& s, string& t)
{
    if(ind1 < 0 || ind2 < 0)
        return 0;
    
    if(s[ind1] == t[ind2])
        return 1 + f(ind1-1, ind2-1, s, t);
    
    return max(f(ind1-1, ind2, s, t), f(ind1, ind2-1, s, t));
}

// dp sol
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

     /* 
    //printing the lcs
    
    
    
    int i = m, j = n;
    
    int len = dp[m][n];
    
    string res = "";
    for(int i = 0; i < len; i++)
    {
        res += '$';
    }
    
    int index = len-1;
    while(i >= 0 && j >= 0)
    {
        if(s[i-1] == t[j-1])
        {
            res[index] = s[i-1];
            index--;
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
        
    }
    
    cout << res << "\n";
    */
    
    
}