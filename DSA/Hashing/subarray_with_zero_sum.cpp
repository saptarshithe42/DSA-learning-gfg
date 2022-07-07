#include<iostream>
#include<unordered_set>
using namespace std;

bool has_zero_sum_subarray(int arr[], int n)
{
    unordered_set<int> h;

    int pre_sum = 0;

    for(int i = 0; i < n; i++)
    {
        pre_sum += arr[i];

        if(h.find(pre_sum) != h.end())
            return true;
        
        if(pre_sum == 0)
            return true;

        h.insert(pre_sum);
    }

    return false;
}

int main()
{
    int arr[] = {1, 4, 13, -3, -10, 5};
    int n = 6;

    cout << std::boolalpha;

    cout << has_zero_sum_subarray(arr, n);
    
    return 0;
}