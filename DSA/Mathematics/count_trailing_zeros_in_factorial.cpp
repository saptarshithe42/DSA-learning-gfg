#include<iostream>
using namespace std;

// Naive solution
// int count_trailing_zeros_in_factorial(int n)
// {
//     int count = 0;

//     int res = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         res *= i;
//     }

//     int dig = res % 10;

//     while (dig == 0)
//     {
//         count++;
//         res = res / 10;
//         dig = res % 10;
//     }


//     return count;
// }


int count_trailing_zeros_in_factorial(int n)
{
    int count  = 0;
    
    for (int i = 5; i <= n; i = i*5)
    {
        count += n / i;
    }
    return count;
}

int main()
{
    cout << count_trailing_zeros_in_factorial(5) << endl;
    cout << count_trailing_zeros_in_factorial(10) << endl;
    cout << count_trailing_zeros_in_factorial(100) << endl;


    return 0;
}