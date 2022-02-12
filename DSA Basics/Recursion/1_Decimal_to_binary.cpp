#include<iostream>
using namespace std;

void dec_to_binary(int n)
{
    if (n == 0)
        return;

    dec_to_binary(n/2);
    cout << (n % 2);
}

int main()
{
    dec_to_binary(7);

    return 0;
}