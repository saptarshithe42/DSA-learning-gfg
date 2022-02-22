#include<iostream>
#include<cmath>
using namespace std;

// time complexity : O((2^n) * n)
void printPowerSet(string s)
{
    int n = s.length();

    int powSize = pow(2, n);

    for (int counter = 0; counter < powSize; counter++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((counter & (1 << j)) != 0)
            {
                cout << s[j];
            }
        }
        cout << "\n";
    }
}

int main()
{
    printPowerSet("abc");

    cout << endl;

    printPowerSet("ab");


    
    return 0;
}