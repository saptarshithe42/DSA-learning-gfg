#include<iostream>
using namespace std;

int getMin(int coins[], int n, int val)
{
    if(val == 0)
        return 0;

    int res = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        if(coins[i] <= val)
        {
            int sub_res = getMin(coins, n, val - coins[i]);

            if(sub_res != INT_MAX)
            {
                res = min(res, sub_res + 1);
            }
        }
    }

    return res;
}



int main()
{
    int coins[] = {9, 6, 5, 1};
    int n = 4;
    int val = 11;

    cout << getMin(coins, n, val);


    
    return 0;
}