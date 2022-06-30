#include<iostream>
using namespace std;

int getMin(int coins[], int n, int val)
{
    int dp[val+1];
    dp[0] = 0;

    for(int i = 1; i <= val; i++)
        dp[i] = INT_MAX;

    for(int i = 1; i <= val; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(coins[j] <= i)
            {
                int sub_res = dp[i - coins[j]];

                if(sub_res != INT_MAX)
                    dp[i] = min(dp[i], sub_res + 1);
            }
        }
    }

    return dp[val];
    
}



int main()
{
    int coins[] = {9, 6, 5, 1};
    int n = 4;
    int val = 11;

    cout << getMin(coins, n, val);


    
    return 0;
}