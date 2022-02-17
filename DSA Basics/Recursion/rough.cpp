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

// int RecursivePower(int n,int p)
//     {
//         //Your code here
//         if (p == 0)
//             return 1;

//         return n * RecursivePower(n,p-1);
//     }

int main()
{
    // int arr[] = {1,2,3,4,5};
    // int n = 5;

    // printArrayRecursively(arr, n);

    // cout << RecursivePower(5,2);
    string s1;
    char s2[50];

    // cout << "\nEnter your full name : ";
    // // cin >> s1;
    // // getline(cin, s1);
    // cin.get(s2, 50); // for character array

    // // cout << "\nYour name is : "  << s1;

    // cout << "\nYour name is : "  << s2;

    string s3 = "Hello World";
    cout << s3 << endl;

    auto it = s3.begin();

    cout << *it << endl;

    it += 6;

    cout << *it << endl;

    // it--;
    it -= 2;

    cout << *it << endl;

    auto bt = s3.end();
    bt -= s3.length();
    cout << *bt << endl;

    cout << to_string(1) + to_string(2) << endl;

    return 0;
}