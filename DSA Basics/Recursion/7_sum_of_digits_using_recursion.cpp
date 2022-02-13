#include<iostream>
using namespace std;

int sumDigits(int n)
{

    if (n == 0)
        return 0;

    return (n % 10) + sumDigits(n / 10);
}


int main()
{
    
    cout << sumDigits(253) << endl;
    cout << sumDigits(9987) << endl;
    cout << sumDigits(10) << endl;


    return 0;
}