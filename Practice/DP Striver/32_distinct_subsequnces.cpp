// https://leetcode.com/problems/distinct-subsequences/

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:


int mod = (int) (1e9 + 7);
// recursive sol
int f(int i, int j, string &t, string &s)
{
    if(j == 0)
        return 1;
    
    if(i == 0)
        return 0;
    
    /*
        - one case is that, character of s and t both match,
          so we move in both, also despite mathching, we don't
          move in t (to which subsequnces are to be compared),
          so that t's characters can be matched with same 
          characters in a different subsequence.

        - second case is that, character of s and t does
          not match, so we move in s(string whose subsequnces
          are to be considered.)

    */

    if(t[i-1] == s[j-1])
        return f(i-1, j-1, t, s) + f(i-1, j, t, s);
    
    return f(i-1, j, t, s);
}


// dp sol
int numDistinct(string s, string t) {
        
        int n = s.length(), m = t.length();

        // return f(n, m, s, t);

        double dp[n+1][m+1];

        for(int i = 0; i <= m; i++)
        {
            dp[0][i] = 0;
        }

        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return (int) dp[n][m];
    }
};