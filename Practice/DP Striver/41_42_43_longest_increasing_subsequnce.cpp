// https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459

#include <bits/stdc++.h>
using namespace std;

// recursive sol

int f(int ind, int prev_ind, int n, int arr[])
{
    if (ind == n)
        return 0;

    int not_take = f(ind + 1, prev_ind, n, arr);

    int take = 0;

    if (prev_ind == -1 || arr[prev_ind] < arr[ind])
        take = 1 + f(ind + 1, ind, n, arr);

    return max(take, not_take);
}

// dp sol

int longestIncreasingSubsequence(int arr[], int n)
{
    //     return f(0, -1, n, arr);

    // dp sol
    /*  
    vector<int> dp(n, 1), hash(n);

    int maxi = 1;
    int lastIndex = 0;
    for (int i = 1; i < n; i++)
    {
        hash[i] = i;
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }

        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    // printing lis

    int lis[maxi];
    lis[0] = arr[lastIndex];

    int ind = 1;
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        lis[ind++] = arr[lastIndex];
    }

    reverse(lis, lis + maxi);

    for (int i = 0; i < maxi; i++)
    {
        cout << lis[i] << " ";
    }

    // length of lis
    return maxi;

    */




     /*
        - use an auxiliary array, say lis.
        - insert first element
        - then, traverse from 1 to n-1 in original array
        - insert element greater than last inserted element
        - if current is smaller than last inserted element,
          then replace its ceiling value by this element.
        - length of this array at the end is the answer.
        - TC : O(nlogn) 
    */
    
    vector<int> lis;
    
    lis.push_back(arr[0]);
    int res = 1;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > lis[res-1])
        {
            lis.push_back(arr[i]);
            res++;
        }
        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            
            lis[it - lis.begin()] = arr[i];
        }
    }
    
    return res;
    
}



