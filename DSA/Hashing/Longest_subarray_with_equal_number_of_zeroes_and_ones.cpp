#include<iostream>
#include<unordered_map>
using namespace std;

int longestSub(int arr[], int n, int sum)
{
    unordered_map<int, int> h;

    int pre_sum = 0;
    int res = 0;

    for(int i = 0; i < n; i++)
    {
        pre_sum += arr[i];

        if(pre_sum == sum)
        {
            res = (i+1);
        }

        if(h.find(pre_sum - sum) == h.end())
            h.insert({pre_sum, i});

        if(h.find(pre_sum - sum) != h.end())
        {
            res = max(res, i - h[pre_sum - sum]);
        }       
    }

    return res;
}

int longest_subarray_with_equal_zeroes_and_ones(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            arr[i] = -1;
    }

    return longestSub(arr, n, 0);
}


int main()
{
    int arr[] = {1, 0, 1, 1, 1, 0, 0};
    int n = 7;

    cout << longest_subarray_with_equal_zeroes_and_ones(arr, n);

    
    return 0;
}