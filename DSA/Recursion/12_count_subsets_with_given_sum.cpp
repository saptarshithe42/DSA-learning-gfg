#include<iostream>
using namespace std;

int count_subsets(int arr[], int n, int sum)
{
    if(n == 0)
    {
        return (sum == 0 ? 1 : 0);
    }

    return count_subsets(arr, n-1, sum) + count_subsets(arr, n-1, sum - arr[n-1]);
}


int main()
{
    int arr[] = {10, 5, 2, 3, 6};
    int n = 5;

    int sum = 8;

    cout << count_subsets(arr, n, sum) << endl;

    return 0;
}