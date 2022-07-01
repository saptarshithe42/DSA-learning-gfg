#include <iostream>
using namespace std;

int minJumps(int arr[], int n)
{
    if(n == 1)
        return 0;

    int res = INT_MAX;
    for (int i = 0; i <= (n-2); i++)
    {
        if(arr[i] + i >= (n-1))
        {
            int sub_res = minJumps(arr, i+1);
            
            if(sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }

    return res;
}

int main()
{
    int arr[] = {3, 4, 2, 1, 2, 1};
    int n = 6;

    cout << minJumps(arr, n);

    return 0;
}