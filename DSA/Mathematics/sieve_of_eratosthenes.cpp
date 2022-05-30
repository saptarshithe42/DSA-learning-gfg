// the job is to print prime numbers less than or equal to the given number n

#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int n);

// naive solution
// time complexity : O(n * n^(1/2))
// void print_prime(int n)
// {
//     for(int i = 2; i <= n; i++)
//     {
//         if (isPrime(i))
//         {
//             cout << i << " ";
//         }
//     }
// }

// simple implementation of sieve

// void sieve(int n)
// {
//     vector<bool> isPrime (n+1, true);

//     for (int i = 2; i*i <= n; i++)
//     {
//         if (isPrime[i])
//         {
//             for (int j = 2*i; j <= n; j = j + i)
//             {
//                 isPrime[j] = false;
//             }
//         }
//     }

//     for (int i = 2; i <= n; i++)
//     {
//         if(isPrime[i])
//             cout << i << " ";
//     }
// }

// more optimized
// void sieve(int n)
// {
//     vector<bool> isPrime (n+1, true);

//     for (int i = 2; i*i <= n; i++)
//     {
//         if (isPrime[i])
//         {
//             for (int j = i*i; j <= n; j = j + i)
//             {
//                 isPrime[j] = false;
//             }
//         }
//     }

//     for (int i = 2; i <= n; i++)
//     {
//         if(isPrime[i])
//             cout << i << " ";
//     }
// }

// shorter, more optimized

void sieve(int n)
{
    vector<bool> isPrime (n+1, true);

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
            for (int j = i*i; j <= n; j = j + i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    // print_prime(10);
    sieve(10);
    cout << endl;

    // print_prime(23);
    sieve(23);
    cout << endl;


    return 0;
}

bool isPrime(int n)
{
    if (n == 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
    {
        if ((n % i == 0) || (n % (i + 2) == 0))
        {
            return false;
        }
    }

    return true;
}