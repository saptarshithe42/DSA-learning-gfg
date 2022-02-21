#include<iostream>
using namespace std;


// naive solution 
// time complexity : theta(total no. of bits in n)
// int count_set_bits(int n)
// {
//     int count = 0;
//     while(n > 0)
//     {
//         // if ((n & 1) == 1)
//         // {
//         //     count++;
//         // }
//         // or
//         count += (n & 1);
//         n = n >> 1;
//     }
//     return count;
// }


// Brian and Kerningam's algorithm
// time complexity : theta(no. of set bits)
// int count_set_bits(int n)
// {
//     int count = 0;

//     while (n > 0)
//     {
//         n = n & (n-1);
//         count++;
//     }
    
//     return count;
// }


// lookup table for 32 bit numbers
// time complexity : theta(1)
// requires a pre-computation , to generate the lookup table

int table[256];

void initialize()
{
    table[0] = 0;
    for (int i = 1; i < 256; i++)
    {
        table[i] = (i & 1) + table[i/2];
    }
}

int count_set_bits(int n)
{
    int count = table[n & 0xff];
    n = n >> 8;
    
    count += table[n & 0xff];
    n = n >> 8;

    count += table[n & 0xff];
    n = n >> 8;

    count += table[n & 0xff];
    return count;
}

int main()
{
    initialize();
    cout << count_set_bits(5) << endl;
    cout << count_set_bits(7) << endl;
    cout << count_set_bits(13) << endl;


    return 0;
}