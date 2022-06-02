#include<iostream>
using namespace std;
int index_of_first_occ(int arr[], int n, int x);

int countOnes(int arr[], int n)
{
    int index = index_of_first_occ(arr, n, 1);

    if (index == -1)
        return 0;
    
    return (n - index);
}


int main()
{
    int arr[] = {1,1,1, 1,1 };

    int n = 5;

    cout << countOnes(arr, n) << endl;

    
    return 0;
}


int index_of_first_occ(int arr[], int n, int x)
{
    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            if(mid == 0 || arr[mid - 1] != arr[mid])
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}