#include <iostream>
#include <string.h>
using namespace std;

int memo[1000][1000];

int lcs(string s1, string s2)
{
    int m = s1.length(), n = s2.length();

    int dp[m+1][n+1];

    for(int i = 0; i <= m; i++)
        dp[i][0] = 0;

    for(int i = 0; i <= n; i++)
        dp[0][i] = 0;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}

int main()
{

    string s1 = "AXYZ", s2 = "BAZ";

    int m = 4, n = 3;


    cout << lcs(s1, s2);
}