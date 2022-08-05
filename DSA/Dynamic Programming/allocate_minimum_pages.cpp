#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int b, int e)
{
    int s = 0;
    for (int i = b; i <= e; i++)
        s += arr[i];
    return s;
}

int minPages(int arr[], int n, int k)
{
    int dp[k + 1][n + 1];
    for (int i = 1; i <= n; i++)
        dp[1][i] = sum(arr, 0, i - 1);
    for (int i = 1; i <= k; i++)
        dp[i][1] = arr[0];

    for (int i = 2; i <= k; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            int res = INT_MAX;
            for (int p = 1; p < j; p++)
            {
                res = min(res, max(dp[i - 1][p], sum(arr, p, j - 1)));
            }
            dp[i][j] = res;
        }
    }
    return dp[k][n];
}

int main()
{
    int arr[] = {10, 20, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << minPages(arr, n, k);
}
