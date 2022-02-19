#include<iostream>
using namespace std;

// Naive solution
// int lcm(int a, int b)
// {
//     int res = max(a, b);
//     while (res <= a*b)
//     {
//         if ((res % a == 0) && (res % b == 0))
//             break;
//         res++;
//     }
//     return res;
// }

// Efficient solution

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}

int main()
{

    cout << lcm(4,6) << endl;
    cout << lcm(12,15) << endl;
    cout << lcm(2, 8) << endl;
    cout << lcm(3, 7) << endl;

    return 0;
}