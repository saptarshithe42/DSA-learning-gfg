#include<iostream>
using namespace std;

// Naive solution
// int gcd(int a, int b)
// {
//     int res = min(a,b);

//     while(res > 0)
//     {
//         if ((a % res == 0) && (b % res == 0))
//         {
//             break;
//         }
//         res--;
//     }

//     return res;
// }


// basic Euclidean Algorithm
// int gcd(int a, int b)
// {
//     while(a != b)
//     {
//         if (a > b)
//             a = a - b;
//         else
//             b = b - a;
//     }

//     return a;
// }

// Optimized implementation of Euclidean Algorithm
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{

    cout << gcd(4,6) << endl;
    cout << gcd(100,200) << endl;
    cout << gcd(7, 13) << endl;

    return 0;
}