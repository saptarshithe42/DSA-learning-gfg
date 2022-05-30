#include<iostream>
using namespace std;

// method 1
// using left shift
// void check_kth_bit(int n, int k)
// {
//    if (n & (1 << (k-1)))
//         cout << "YES" << endl;
//     else
//         cout << "NO" << endl;
// }

// method 2
// using right shift
void check_kth_bit(int n, int k)
{
   if (((n >> (k-1)) & 1) == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    check_kth_bit(5,1); 
    cout << endl;
    check_kth_bit(8,2); 
    cout << endl;
    check_kth_bit(0,3); 
    cout << endl;



    return 0;
}