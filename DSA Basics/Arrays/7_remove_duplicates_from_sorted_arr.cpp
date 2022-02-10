#include<iostream>
using namespace std;


// my sol
// int remove_duplicates(int arr[], int n)
// {
//     int size = 1;

//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] != arr[i - 1])
//         {
//             arr[size] = arr[i];
//             size++;
//         }
//     }

//     return (size);
// }

// gfg sol
int remove_duplicates(int arr[], int n)
{
    int size = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[size - 1])
        {
            arr[size] = arr[i];
            size++;
        }
    }

    return (size);
}


int main()
{
    int a1[] = {10, 20, 20, 30, 30, 30, 30};
    int a2[] = {10, 10, 10};

    int n1 = remove_duplicates(a1, 7);

    cout << "\n";
    for (int i = 0; i < n1; i++)
    {
        cout << a1[i] << " ";
    }

    int n2 = remove_duplicates(a2, 3);

    cout << "\n";
    for (int i = 0; i < n2; i++)
    {
        cout << a2[i] << " ";
    }



    
    return 0;
}