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


int main()
{

    int arr[] = {5, 8, -4, -4, 9, -2, 2};
    int n = 7;
    int sum = 0;

    cout << longestSub(arr, n, sum);

    
    return 0;
}