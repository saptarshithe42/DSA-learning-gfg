#include<iostream>
using namespace std;

int ceilIdx(int tail[], int l, int r, int x)
{
    while(r > l)
    {
        int m = l + (r - l) / 2;
        if(tail[m] >= x)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }

    return r;
}

int lis(int arr[], int n)
{   
    int tail[n], len = 1;
    tail[0] = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > tail[len-1])
        {
            tail[len] = arr[i];
            len++;
        }
        else
        {
            int c = ceilIdx(tail, 0, len-1, arr[i]);
            tail[c] = arr[i];
        }
    }

    return len;
}


int main()
{

    int arr[] = {3, 4, 2, 8, 10};
    int n = 5;

    cout << lis(arr, n);

    return 0;
}