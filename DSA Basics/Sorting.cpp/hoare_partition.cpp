#include<iostream>
using namespace std;


// time complexity : O(n)
// space complexity : O(1)
int hoare_partition(int arr[], int l, int h)
{
    int i = l - 1, j = h + 1;
    int pivot = arr[l];

    while (true)
    {
        do
        {
            i++;
        } while(arr[i] < pivot);
        do
        {
            j--;
        } while(arr[j] > pivot);

        if (i >= j) return j;

        swap(arr[i], arr[j]);
    }
}

int main()
{
    int arr[] = {5,3,8,4,2,7,1,10};

    cout << "Initial array : ";
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";

    int n = hoare_partition(arr, 0, 7);

    cout << "Partitioned array : ";
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";
    cout << n;


    return 0;
}