#include <iostream>
using namespace std;


// time complexity : O(n^2)
// space complexity : O(1)
// O(n) in best case (sorted array), worst case : Reverse sorted array
void insertion_sort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while ((j >= 0) && (arr[j] > key))
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main()
{
    int arr1[] = {2, 8, 7, 10};

    cout << "\nInitial array : ";

    for (int x : arr1)
    {
        cout << x << " ";
    }

    insertion_sort(arr1, 4);

    cout << "\nSorted array : ";
    for (int x : arr1)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}