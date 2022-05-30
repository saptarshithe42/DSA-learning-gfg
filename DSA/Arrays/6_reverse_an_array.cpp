#include <iostream>
using namespace std;

// my sol
// void reverse_arr(int arr[], int n)
// {
//     int t;
//     for (int i = 0; i <= n / 2; i++)
//     {
//         t = arr[i];
//         arr[i] = arr[n - i - 1];
//         arr[n - i - 1] = t;
//     }
// }

// gfg sol

void reverse_arr(int arr[], int n)
{
    int low = 0, high = n - 1;

    while (low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

int main()
{
    int a1[] = {10, 5, 8, 20};

    int a2[] = {20, 10, 20, 8, 12};

    int a3[] = {10, 10 ,10};

    reverse_arr(a1, 4);
    reverse_arr(a2, 5);
    reverse_arr(a3, 3);

    cout << "\n";

    for (int i = 0; i < 4; i++)
    {
        cout << a1[i] << " ";
    }

    cout << "\n";

    for (int i = 0; i < 5; i++)
    {
        cout << a2[i] << " ";
    }

    cout << "\n";

    for (int i = 0; i < 3; i++)
    {
        cout << a3[i] << " ";
    }

    return 0;
}