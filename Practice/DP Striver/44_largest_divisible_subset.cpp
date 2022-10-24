/// https://www.codingninjas.com/codestudio/problems/divisible-set_3754960

#include <bits/stdc++.h> 
using namespace std;

vector<int> divisibleSet(vector<int> &arr){
    // Write your code here.
    int n = arr.size();
    /*
        - sort the array
        - now go in increasing order with divisibility
        - e.g. : suppose, after sorting : {1,4,8,16}
        
        so, 1 divides 4.
        4 divides 8, which in turn means 1 divides 8 as well
        similarly, 8 divides 16, so indirectly 4 and 1 divide
        16 as well. So, in every pair the required condition
        is satisfied. That's why sorting was required.
        Have to use printing lIS logic.
    
    */
    
    sort(arr.begin(), arr.end());
    
    vector<int> dp(n, 1), hash(n);

    int maxi = 1;
    int lastIndex = 0;
    for (int i = 1; i < n; i++)
    {
        hash[i] = i;
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if ((arr[i] % arr[j] == 0) && 1 + dp[j] > dp[i])
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

    vector<int> lis(maxi, 0);
    lis[0] = arr[lastIndex];

    int ind = 1;
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        lis[ind++] = arr[lastIndex];
    }

    return lis;
}