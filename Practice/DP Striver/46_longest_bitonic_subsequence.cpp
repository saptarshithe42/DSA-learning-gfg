// https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688

#include <bits/stdc++.h> 
using namespace std;



int longestBitonicSequence(vector<int>& arr, int n) {
    
    /*
        - store LIS of each element, traversing from
        left to right, as well as right to left.
        - take max value of sum of these two lis values
        for each element, this sum - 1 is the answer, as this element is common in both lis.
    */
	 
    vector<int> backward(n,1);
    
    vector<int> rev = arr;
    reverse(rev.begin(), rev.end());
 
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
            }
        }
    }
    
    for (int i = 1; i < n; i++)
    {
        backward[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (rev[j] < rev[i] && 1 + backward[j] > backward[i])
            {
                backward[i] = 1 + backward[j];
            }
        }
    }
    
    
    int maxi = 0;
    
    for(int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp[i] + backward[n-1-i]);
    }
    
    return (maxi - 1);
    
} 
