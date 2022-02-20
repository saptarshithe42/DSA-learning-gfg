#include<iostream>
using namespace std;


// naive solution
// time complexity : theta(n)
// int compute_power(int x, int n)
// {
//     int res = 1;

//     for (int i = 1; i <= n; i++)
//     {
//         res = res * x;
//     }
//     return res;
// }


// efficient solution (but recursive, next one is better)
// time complexity : O(logn)
// aux space : O(logn)
// int compute_power(int x, int n)
// {
//     if (n == 0)
//         return 1;

//     int temp = compute_power(x, n/2);
//     temp = temp * temp;

//     if (n % 2 == 0)
//         return temp;
//     else
//         return temp*x;
// }


// better solution (iterative)
int compute_power(int x, int n)
{
    int res = 1;
    while(n > 0)
    {
        if(n % 2 != 0)
        {
            res = res * x;
        }
        n = n/2;
        x = x*x;
    }
    return res;
}

int main()
{

    cout << compute_power(2, 3) << endl;
    cout << compute_power(3, 4) << endl;
    cout << compute_power(5, 0) << endl;
    cout << compute_power(5, 1) << endl;


    return 0;
}