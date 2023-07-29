// https://leetcode.com/problems/palindrome-partitioning-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int start, int end, string &s)
    {

        int low = start, high = end;

        while (low <= high)
        {

            if (s[low] != s[high])
                return false;

            low++;
            high--;
        }

        return true;
    }

    int f(int i, string &s)
    {

        int n = s.size();

        if (i == n)
            return 0;

        int minCost = INT_MAX;
        // front partitioning
        // if substring from i to j is palindrome, consider that and solve for remaining part (j+1)
        for (int j = i; j < n; j++)
        {

            if (isPalindrome(i, j, s))
            {
                int cost = 1 + f(j + 1, s);
                minCost = min(minCost, cost);
            }
        }

        return minCost;
    }

    int f(int i, string &s, vector<int> &dp)
    {

        int n = s.size();

        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int minCost = INT_MAX;

        for (int j = i; j < n; j++)
        {

            if (isPalindrome(i, j, s))
            {
                int cost = 1 + f(j + 1, s, dp);
                minCost = min(minCost, cost);
            }
        }

        return dp[i] = minCost;
    }

    int minCut(string s)
    {

        int n = s.size();

        // return f(0, s)-1;

        // vector<int> dp (n, -1);

        // return f(0, s, dp)-1;

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int minCost = INT_MAX;
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(i, j, s))
                {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }

            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
};