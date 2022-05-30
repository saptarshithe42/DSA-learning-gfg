#include<iostream>
using namespace std;

int maxConsecutive_1s(int arr[], int n)
{
    int max_count = 0;

    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count = 0;
        }
        else
        {
            count++;
            max_count = max(max_count, count);
        }
    }

    return max_count;
}


int main()
{
    // int arr[] = {0,1,1,0,1,0};
    // int n = 6;

    int arr[] = {1,1,1,1};
    int n = 4;


    // int arr[] = {0,0,0};
    // int n = 3;

    // int arr[] = {1,0,1,1,1,1,0,1,1};
    // int n = 9;

    cout << maxConsecutive_1s(arr, n) << endl;


    
    return 0;
}