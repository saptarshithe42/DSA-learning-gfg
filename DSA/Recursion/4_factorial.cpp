#include<iostream>
using namespace std;


// non tail recursive
int factorial_non_tail(int n)
{
    if ((n == 0) || (n == 1))
        return 1;
    
    return  n * factorial_non_tail(n-1);
}


// tail recursive

// initally pass k = 1
int factorial_tail(int n, int k)
{
    if ((n == 0) || (n == 1))
        return k;
    
    return  factorial_tail(n-1, k*n);
}


int main()
{
    cout << factorial_non_tail(5) << endl;
    cout << factorial_tail(5, 1) << endl;


    
    return 0;
}