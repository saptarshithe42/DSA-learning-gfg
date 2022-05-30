#include<iostream>
#include<cmath>
using namespace std;

// iterative
int count_digits_1(int n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n = n/10;
    }
    return count;
}

// recursive

int count_digits_2(int n)
{
    if (n == 0)
        return 0;

    return 1 + count_digits_2(n/10);
}

// using log

int count_digits_3(int n)
{
    return floor(log10(n) + 1);
}


int main()
{

    int n = 446677;

    cout << count_digits_1(n) << endl;
    cout << count_digits_2(n) << endl;
    cout << count_digits_3(n) << endl;

    
    return 0;
}