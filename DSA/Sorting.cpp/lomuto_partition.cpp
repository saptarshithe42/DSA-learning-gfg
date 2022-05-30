#include<iostream>
using namespace std;

// time complexity : O(n)
// space complexity : O(1)
int lomuto_partition(int arr[], int l, int h)
{
    int i = l - 1;
    int pivot = arr[h];
    for(int j = l; j <= h-1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[h]);

    return (i+1);
}

int main()
{
    int arr[] = {10,80,30,90,40,50,70};

    cout << "Initial array : ";
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";

    int n = lomuto_partition(arr, 0, 6);

    cout << "Partitioned array : ";
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";
    cout << n;


    return 0;
}