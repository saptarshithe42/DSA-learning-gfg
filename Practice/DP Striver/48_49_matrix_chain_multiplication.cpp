// https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_975344?topList=striver-sde-sheet-problems

#include <bits/stdc++.h>
using namespace std;

// recursive sol
int f(int i, int j, vector<int> &arr)
{
    if (i == j)
        return 0;

    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        mini = min(mini, arr[i - 1] * arr[k] * arr[j] + f(i, k, arr) + f(k + 1, j, arr));
    }

    return mini;
}

// dp sol
int matrixMultiplication(vector<int> &arr, int N)
{

    //     return f(1, N-1, arr);

    int dp[N][N];

    for (int i = 1; i < N; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            dp[i][j] = 1e9;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j]);
            }
        }
    }

    return dp[1][N - 1];
}
