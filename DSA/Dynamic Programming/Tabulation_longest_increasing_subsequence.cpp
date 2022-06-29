#include<iostream>
using namespace std;

int lis(int arr[], int n)
{   
    int lis[n];
    lis[0] = 1;

    for(int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    int res = lis[0];

    for(int i = 1; i < n; i++)
    {
        res = max(res, lis[i]);
    }

    return res;
}


int main()
{

    int arr[] = {3, 4, 2, 8, 10};
    int n = 5;

    cout << lis(arr, n);

    return 0;
}