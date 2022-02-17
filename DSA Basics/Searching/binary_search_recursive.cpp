#include<iostream>
using namespace std;


// time complexity : O(logn)
// space complexity : O(logn)

int binary_search_recursive(int arr[], int low, int high, int x)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;

    if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] > x)
    {
        return binary_search_recursive(arr, low, mid - 1, x);
    }

    else
    {
        return binary_search_recursive(arr, mid + 1, high, x);
    }

}


int main()
{
    

    int arr[] = {20, 20, 30, 40, 50, 50}, n = 6;

    int x = 50;

    cout << binary_search_recursive(arr, 0, n -1, x);
    return 0;


    return 0;
}