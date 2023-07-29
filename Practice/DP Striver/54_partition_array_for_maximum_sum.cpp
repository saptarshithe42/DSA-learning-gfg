// https://leetcode.com/problems/partition-array-for-maximum-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //recursive sol
    int f(int i, int k, vector<int> &arr)
    {

        int n = arr.size();

        if (i == n)
            return 0;

        int maxSum = INT_MIN;

        for (int j = i; j < n; j++)
        {

            int len = j - i + 1;

            if (len <= k)
            {

                int maxElement = *max_element(arr.begin() + i, arr.begin() + j + 1);

                int sum = (maxElement * len) + f(j + 1, k, arr);

                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }

    // memoization
    int f(int i, int k, vector<int> &arr, vector<int> &dp)
    {

        int n = arr.size();

        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int maxSum = INT_MIN;

        for (int j = i; j < n; j++)
        {

            int len = j - i + 1;

            if (len <= k)
            {

                int maxElement = *max_element(arr.begin() + i, arr.begin() + j + 1);

                int sum = (maxElement * len) + f(j + 1, k, arr, dp);

                maxSum = max(maxSum, sum);
            }
        }

        return dp[i] = maxSum;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {

        // return f(0, k, arr);

        int n = arr.size();

        // vector<int> dp (n, -1);

        // return f(0, k, arr, dp);

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int maxSum = INT_MIN;

            for (int j = i; j < n; j++)
            {

                int len = j - i + 1;

                if (len <= k)
                {

                    int maxElement = *max_element(arr.begin() + i, arr.begin() + j + 1);

                    int sum = (maxElement * len) + dp[j + 1];

                    maxSum = max(maxSum, sum);
                }
            }

            dp[i] = maxSum;
        }

        return dp[0];
    }
};