#include<iostream>
using namespace std;

int count_set_bits(int n)
{
    int count = 0;

    while(n > 0)
    {
        n = n & (n-1);
        count++;
    }

    return count;
}

bool check_power2(int n)
{
    // if (n % 2 != 0)
    // {
    //     return false;
    // }

    // if (count_set_bits(n) == 1)
    // {
    //     return true;
    // }
    // return false;

    // or

    // a number which is a power of 2
    // will have only one set bit
    // so unset that bit and if it becomes zero ,
    // then it is power of 2, otherwise not.

    if (n == 0)
        return false;
    
    return ((n & (n-1)) == 0);

}

int main()
{
    cout << std::boolalpha;
    cout << check_power2(4) << endl;
    cout << check_power2(6) << endl;



    return 0;
}