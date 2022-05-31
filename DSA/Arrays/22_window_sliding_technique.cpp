#include<iostream>
using namespace std;

// window sliding technique

// find maximum sum of k consecutive elements

int maxSum(int arr[], int n, int k)
{
    int curr_sum = 0;

    for(int i = 0; i < k; i++)
    {
        curr_sum += arr[i];
    }

    int max_sum = curr_sum;

    for(int i = k; i < n; i++)
    {
        curr_sum += (arr[i] - arr[i-k]);
        max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
}




int main()
{
    int arr[] = {5, -10, 6, 90, 3};
    int n = 5;
    int k = 2;

    cout << "\nmax sum = " << maxSum(arr, n, k) << endl;
    
    return 0;
}