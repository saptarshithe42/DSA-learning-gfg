#include<iostream>
using namespace std;

// my sol
// void print_n_to_one(int n)
// {
//     if (n == 1)
//     {
//         cout << 1;
//         return;
//     }

//     cout << n << " ";

//     print_n_to_one(n - 1);
    
// }


// gfg sol
void print_n_to_one(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << " ";

    print_n_to_one(n - 1);
    
}

int main()
{
    print_n_to_one(5);

    cout << "\n";

    print_n_to_one(2);


    
    return 0;
}