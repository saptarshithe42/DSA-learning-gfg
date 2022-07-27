#include<iostream>
using namespace std;

// time complexity : theta(n)
// space complexity : theta(n)
int naive_partition(int arr[], int l, int h, int p)
{
    int temp[h - l + 1], index  = 0;

    for (int i = l; i <= h; i++)
    {
        if (arr[i] < arr[p])
        {
            temp[index] = arr[i];
            index++;
        }
    }

    for (int i = l; i <= h; i++)
    {
        if (arr[i] == arr[p])
        {
            temp[index] = arr[i];
            index++;
        }
    }

    int res = l + index - 1;

    for (int i = l; i <= h; i++)
    {
        if (arr[i] > arr[p])
        {
            temp[index] = arr[i];
            index++;
        }
    }

    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[i-l];
    }

    return res;
}

int main()
{
    int arr1[] = {3,8,6,12,10,7};
    // int arr1[] = {2,7,8,3,7};
    int p = 5;
    int new_ind = naive_partition(arr1, 0, 6, p);

    for (int x : arr1)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << new_ind;

    return 0;
}