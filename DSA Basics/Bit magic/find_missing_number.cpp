#include<iostream>
using namespace std;

int findMissing(int arr[], int n)
{
    int res1 = 0, res2 = 0;

    for (int i = 0; i < n; i++)
    {
        res1 = res1 ^ arr[i];
    }

    for (int i = 1; i <= (n+1); i++)
    {
        res2 = res2 ^ i;
    }

    return (res1 ^ res2);
}

int main()
{
    int arr1[] = {1,4,3};
    int arr2[] = {1,5,3,2};

    cout << findMissing(arr1, 3) << endl;
    cout << findMissing(arr2, 4) << endl;


    
    return 0;
}