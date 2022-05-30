#include<iostream>
using namespace std;


// my sol
// void left_rotate_arr(int arr[], int n)
// {
//     int first = arr[0];

//     for (int i = 0; i < n -1; i++)
//     {
//         arr[i] = arr[i+1];
//     }

//     arr[n - 1] = first;
// }

// gfg sol
void left_rotate_arr(int arr[], int n)
{
    int first = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i-1] = arr[i];
    }

    arr[n - 1] = first;
}

int main()
{
    int a1[] = {1,2,3,4,5};
    int a2[] = {30, 5, 20};

    cout << "\n";
    left_rotate_arr(a1, 5);
    left_rotate_arr(a2, 3);

    for (int x : a1)
    {
        cout << x << " ";
    }

    cout << "\n";

    for (int x : a2)
    {
        cout << x << " ";
    }

    
    return 0;
}