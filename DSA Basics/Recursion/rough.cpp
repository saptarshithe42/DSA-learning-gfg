#include <iostream>
using namespace std;

// void printArrayRecursively(int arr[], int n)
// {
//     //Your code here
//     //Use recursion to print array elements from start to end
//     if (n == 0)
//         return;

//     printArrayRecursively(arr, n - 1);

//     cout << arr[n-1] << " ";
// }

int RecursivePower(int n,int p)
    {
        //Your code here
        if (p == 0)
            return 1;
        
        return n * RecursivePower(n,p-1);
    }

int main()
{
    // int arr[] = {1,2,3,4,5};
    // int n = 5;

    // printArrayRecursively(arr, n);

    cout << RecursivePower(5,2);

    return 0;
}