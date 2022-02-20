#include <iostream>
using namespace std;

// naive solution
// time complexity : O(n)
// void all_divisors(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             cout << i << " ";
//         }
//     }
// }

// efficient code - (but doesn't print in increasing order)
// time complexity : O(n^(1/2))
// void all_divisors(int n)
// {
//     for (int i = 1; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             cout << i << " ";
//             if (i != (n / i))
//             {
//                 cout << (n / i) << " ";
//             }
//         }
//     }
// }

// efficient code - (but doesn't print in increasing order)
// time complexity : O(n^(1/2))
void all_divisors(int n)
{
    int i;
    for (i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }

    for (; i >= 1; i--)
    {
        if (n % i == 0)
        {
            cout << (n/i) << " ";
        }
    }


}



int main()
{
    all_divisors(15);
    cout << "\n";

    all_divisors(100);
    cout << "\n";

    all_divisors(7);
    cout << "\n";

    return 0;
}