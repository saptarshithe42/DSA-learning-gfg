#include <iostream>
using namespace std;


// logn iterations

// time complexity : O(logn)
// space complexity : O(1)

// iterative solution is better than the recursive solution

int binary_search_iterative(int arr[], int n, int x)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }

        else if (arr[mid] > x)
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{

    int arr[] = {20, 20, 30, 40, 50, 60}, n = 6;

    int x = 20;

    cout << binary_search_iterative(arr, n, x);
    return 0;

}