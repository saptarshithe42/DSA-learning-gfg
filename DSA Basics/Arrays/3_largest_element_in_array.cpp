#include <iostream>
using namespace std;

int get_largest(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[res])
        {
            res = i;
        }
    }
    return (res); // index of largest element
}

int main()
{

    int a1[] = {10, 5, 8, 20};

    int a2[] = {20, 10, 20, 8, 12};

    int a3[] = {10, 10, 10};

    cout << get_largest(a1, 4) << "\n";
    cout << get_largest(a2, 5) << "\n";
    cout << get_largest(a3, 3) << "\n";

    return 0;
}