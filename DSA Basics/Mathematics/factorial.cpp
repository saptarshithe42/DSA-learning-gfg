#include<iostream>
using namespace std;

// iterative
int factorial(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

// recursive
// int factorial(int n)
// {
//     if ((n == 0) || (n == 1))
//         return 1;
//     return n*factorial(n-1);
// }


int main()
{
    cout << factorial(5) << endl;
    cout << factorial(1) << endl;
    cout << factorial(0) << endl;
    cout << factorial(7) << endl;




    return 0;
}