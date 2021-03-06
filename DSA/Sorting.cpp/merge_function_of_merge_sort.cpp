#include <iostream>
using namespace std;

// gfg sol
void merge(int arr[], int l, int m, int h)
{

    int n1 = m - l + 1, n2 = h - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

int main()
{
    int a1[] = {10, 15, 20, 11, 30};
    merge(a1, 0, 2, 4);

    for (int x : a1)
    {
        cout << x << " ";
    }
    cout << "\n";

    int a2[] = {5, 8, 12, 14, 7};
    merge(a2, 0, 3, 4);
    for (int x : a2)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}