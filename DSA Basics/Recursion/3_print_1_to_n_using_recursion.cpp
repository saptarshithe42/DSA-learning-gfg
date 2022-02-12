#include<iostream>
using namespace std;

// non tail recursive
void print_one_to_n(int n)
{
    if (n == 0)
    {
        return;
    }
    print_one_to_n(n-1);
    cout << n << " ";
}

// tail recursive solution
// initally pass k = 1
void print_one_to_n_tail(int n, int k)
{
    if (n == 0)
    {
        return;
    }
    cout << k << " ";
    print_one_to_n_tail(n-1, k+1);
}



int main()
{
    print_one_to_n(4);
    cout << "\n";
    print_one_to_n_tail(5, 1);
    
    return 0;
}