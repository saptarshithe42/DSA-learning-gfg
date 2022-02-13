#include<iostream>
using namespace std;

/// my sol
// int getSum(int n)
// {
//     if (n == 1)
//         return 1;
//     return (n + getSum(n-1));
// }

// gfg sol
// int getSum(int n)
// {
//     if (n == 0)
//         return 0;
//     return (n + getSum(n-1));
// }

// my try for making a tail recurive function
//pass k = 0 initially
int getSum(int n, int k)
{
    if (n == 0)
        return k;
    return getSum(n-1, k + n);
}

int main()
{
    
    // cout << getSum(2) << endl;
    // cout << getSum(4) << endl;
    // cout << getSum(5) << endl;
     cout << getSum(2, 0) << endl;
    cout << getSum(4, 0) << endl;
    cout << getSum(5, 0) << endl;

    return 0;
}