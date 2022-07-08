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

int longest_common_subarray(int arr1[], int arr2[], int n)
{
    int temp[n];

    for(int i = 0; i < n; i++)
    {
        temp[i] = arr1[i] - arr2[i];
    }

    return longestSub(temp, n, 0);
}


int main()
{

    int arr1[] = {0, 1, 0, 0, 0, 0};
    int arr2[] = {1, 0, 1, 0, 0, 1};
    int n = 6;

    cout << longest_common_subarray(arr1, arr2, n);

    
    return 0;
}